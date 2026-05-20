import os
import re
import sys

FAILED = False

FORBIDDEN_WORDS = [
    "printf(",
    "TODO",
]

CHECK_EXTENSIONS = [
    ".c",
    ".cpp",
    ".h",
    ".hpp",
]


def report(path, line_no, message):
    global FAILED
    FAILED = True
    print(f"[ERROR] {path}:{line_no} -> {message}")


def should_check(file_name):
    return any(file_name.endswith(ext) for ext in CHECK_EXTENSIONS)


def check_missing_braces(path, lines):

    patterns = [
        r'^\s*for\s*\(.*\)\s*$',
        r'^\s*if\s*\(.*\)\s*$',
        r'^\s*while\s*\(.*\)\s*$',
        r'^\s*else\s*$',
    ]

    for i, line in enumerate(lines):

        stripped = line.strip()

        # Ignore comments
        if stripped.startswith("//"):
            continue

        for pattern in patterns:

            if re.match(pattern, stripped):

                # Already has {
                if stripped.endswith("{"):
                    break

                # Find next non-empty line
                j = i + 1

                while j < len(lines):

                    next_line = lines[j].strip()

                    # Skip empty line
                    if next_line == "":
                        j += 1
                        continue

                    # Skip comments
                    if next_line.startswith("//"):
                        j += 1
                        continue

                    # Pass if next line starts with {
                    if next_line.startswith("{"):
                        break

                    # Fail
                    report(
                        path,
                        i + 1,
                        "Missing braces for control statement"
                    )

                    break

                break


def check_file(path):

    try:
        with open(path, "r", encoding="utf-8", errors="ignore") as f:

            lines = f.readlines()

            # Check braces
            check_missing_braces(path, lines)

            for line_no, line in enumerate(lines, start=1):

                stripped = line.rstrip("\n")

                # Rule 1: TAB forbidden
                if "\t" in line:
                    report(path, line_no, "TAB character is forbidden")

                # Rule 2: line too long
                if len(stripped) > 120:
                    report(path, line_no, "Line too long (>120)")

                # Rule 3: trailing whitespace
                if stripped.endswith(" "):
                    report(path, line_no, "Trailing whitespace found")

                # Rule 4: forbidden words
                for word in FORBIDDEN_WORDS:
                    if word in line:
                        report(
                            path,
                            line_no,
                            f"Forbidden keyword: {word}"
                        )

    except Exception as e:
        report(path, 0, f"Failed to read file: {e}")


def scan(root_dir):

    SKIP_DIRS = {
        ".git",
        ".vs",
        "build",
        "out",
        "Debug",
        "Release",
    }

    for root, dirs, files in os.walk(root_dir):

        # Skip directories
        dirs[:] = [d for d in dirs if d not in SKIP_DIRS]

        for file_name in files:

            if should_check(file_name):

                full_path = os.path.join(root, file_name)

                check_file(full_path)


if __name__ == "__main__":

    target = "."

    if len(sys.argv) > 1:
        target = sys.argv[1]

    print("====================================")
    print(" Running Convention Checker")
    print("====================================")

    scan(target)

    print("====================================")

    if FAILED:
        print("Convention check FAILED")
        sys.exit(1)

    print("Convention check PASSED")
    sys.exit(0)
