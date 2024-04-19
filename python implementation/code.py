import sys

def pigeonhole_sort(arr):
    # Find minimum and maximum values in the array
    min_val = min(arr)
    max_val = max(arr)

    # Calculate the range of values
    size = max_val - min_val + 1

    # Create pigeonhole list
    holes = [0] * size

    # Populate pigeonholes
    for x in arr:
        holes[x - min_val] += 1

    # Reconstruct the array
    index = 0
    for i in range(size):
        while holes[i] > 0:
            arr[index] = i + min_val
            index += 1
            holes[i] -= 1

# Main function to take input from the file and sort the array
def main():
    filename = "input1.txt"
    arr = []

    # Open the file for reading
    with open(filename, 'r') as file:
        # Read integers from the file
        for line in file:
            line = line.strip()  # Remove any leading/trailing whitespace
            try:
                num = int(line)  # Attempt to convert the line to an integer
                arr.append(num)
            except ValueError:
                print(f"Skipping invalid input: {line}")

    pigeonhole_sort(arr)

    # Convert sorted numbers to a string
    sorted_output = ' '.join(map(str, arr))

    print("Sorted order is:")
    print(sorted_output)
    
    # Flush the standard output stream
    sys.stdout.flush()

if _name_ == "_main_":
    main()
