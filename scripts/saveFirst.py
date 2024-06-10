import sys

def process_file(input_file, output_file):
    data = {}

    # Read the input file
    with open(input_file, 'r') as file:
        for line in file:
            value1, value2 = line.split()
            value1 = float(value1)
            value2 = float(value2)

            # Save the first appearance of each value in the second column
            if value2 not in data:
                data[value2] = value1

    # Write the results to the output file
    with open(output_file, 'w') as file:
        for value2 in sorted(data.keys()):
            file.write(f"{data[value2]} {value2}\n")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input_file> <output_file>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]
    process_file(input_file, output_file)
