class StatisticsCalculator:
    """A class to calculate basic statistics on a list of integers."""

    def __init__(self, data):
        """Initialize with a list of integers."""
        self.data = data.copy()  # Store a copy to avoid external modifications

    def calculate_mean(self):
        """Calculate and return the mean (average) of the data."""
        if not self.data:
            return 0
        return sum(self.data) / len(self.data)

    def calculate_median(self):
        """Calculate and return the median of the data."""
        if not self.data:
            return 0

        sorted_data = sorted(self.data)
        n = len(sorted_data)

        if n % 2 == 0:
            # Even number of elements
            return (sorted_data[n//2 - 1] + sorted_data[n//2]) / 2
        else:
            # Odd number of elements
            return sorted_data[n//2]

    def calculate_mode(self):
        """Calculate and return the mode(s) of the data."""
        if not self.data:
            return []

        # Count frequencies using dictionary
        frequency = {}
        for num in self.data:
            frequency[num] = frequency.get(num, 0) + 1

        # Find maximum frequency
        max_count = max(frequency.values())

        # Return all values with maximum frequency
        modes = [num for num, count in frequency.items() if count == max_count]
        return sorted(modes)  # Sort for consistent output

    def get_data(self):
        """Return a copy of the current data."""
        return self.data.copy()

    def set_data(self, new_data):
        """Set new data for calculations."""
        self.data = new_data.copy()

    def display_statistics(self):
        """Display all statistics in a formatted way."""
        print(f"Data: {self.data}")
        print(f"Mean: {self.calculate_mean():.2f}")
        print(f"Median: {self.calculate_median():.2f}")
        print(f"Mode(s): {self.calculate_mode()}")


def main():
    """Main function to demonstrate the StatisticsCalculator class."""
    # Sample data
    data = [1, 2, 2, 3, 4, 4, 5]

    print("=== Python Statistics Calculator (Object-Oriented) ===")

    # Create calculator instance
    calculator = StatisticsCalculator(data)

    # Display all statistics
    calculator.display_statistics()

    print("\n=== Testing with different data ===")
    # Test with different data
    calculator.set_data([1, 1, 2, 3, 3, 3, 4])
    calculator.display_statistics()


if __name__ == "__main__":
    main()