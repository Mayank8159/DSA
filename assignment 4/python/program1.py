class Time:
    def __init__(self, hours, minutes, seconds):
        self.hours = hours
        self.minutes = minutes
        self.seconds = seconds

    def to_seconds(self):
        return self.hours * 3600 + self.minutes * 60 + self.seconds

def get_time_input(label):
    h, m, s = map(int, input(f"Enter {label} time (hh mm ss): ").split())
    return Time(h, m, s)

def main():
    start = get_time_input("start")
    end = get_time_input("end")

    start_seconds = start.to_seconds()
    end_seconds = end.to_seconds()

    diff_seconds = end_seconds - start_seconds

    # Handle wrap-around if event ends the next day
    if diff_seconds < 0:
        diff_seconds += 24 * 3600

    # Convert back to hh:mm:ss
    hours = diff_seconds // 3600
    diff_seconds %= 3600
    minutes = diff_seconds // 60
    seconds = diff_seconds % 60

    print(f"Difference: {hours} hours, {minutes} minutes, {seconds} seconds")
    print(f"Total difference in seconds: {hours * 3600 + minutes * 60 + seconds}")

if __name__ == "__main__":
    main()