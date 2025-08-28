
N = int(input("Enter number of students: "))

max_ratio = 0.0  # To store the highest ratio

# Loop through each student
for i in range(N):
    print(f"Student {i + 1}:")
    height = float(input("  Enter height: "))
    weight = float(input("  Enter weight: "))

    if height != 0:
        ratio = weight / height
        if ratio > max_ratio:
            max_ratio = ratio

# Show the result
print(f"\nHighest weight/height ratio is: {max_ratio:.2f}")