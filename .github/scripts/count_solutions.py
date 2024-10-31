import os

# Define folders for each category and the total problems in each
categories = {
    "Introductory Problems": ("Introductory_Problems", 19),  # Replace with actual total count
    "Sorting&Searching": ("Sorting&Searching", 35),
    "DP": ("DP", 19),
    "Graphs": ("Graphs", 36),
    "Trees": ("Trees", 16),
    "Strings": ("Strings", 17),  # Replace with actual total count
    "Range Queries": ("Range_Queries", 19),  # Replace with actual total count
    "Geometry": ("Geometry", 7)  # Replace with actual total count
}

# Function to count solutions in each category
def count_solutions():
    solved_counts = {}
    for category, (folder, total) in categories.items():
        try:
            solved = len([f for f in os.listdir(folder) if os.path.isfile(os.path.join(folder, f))])
        except FileNotFoundError:
            solved = 0
        solved_counts[category] = (solved, total)
    return solved_counts

# Update README file
def update_readme(solved_counts):
    with open("README.md", "r") as file:
        lines = file.readlines()
    
    # Find the table section in README
    start = end = None
    for i, line in enumerate(lines):
        if line.strip() == "| 📂 Section               | 🔢 Solved Problems |":
            start = i + 2
        if start and line.strip() == "":
            end = i
            break

    # Generate updated table lines
    table_lines = [
        f"| 🌱 {category}          | {solved} / {total}           |\n"
        for category, (solved, total) in solved_counts.items()
    ]

    # Update README file with new table
    updated_lines = lines[:start] + table_lines + lines[end:]
    with open("README.md", "w") as file:
        file.writelines(updated_lines)

# Run script
if __name__ == "__main__":
    solved_counts = count_solutions()
    update_readme(solved_counts)
