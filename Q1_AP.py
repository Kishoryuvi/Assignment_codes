def is_key_in_ap(a1, a2, a3, key):
    # Calculate the common difference
    d = a2 - a1

    # Check if the key can be reached from a1 with some multiple of d
    if d == 0:
        return key == a1  # If d is 0, all elements in the AP are the same

    n = (key - a1) / d

    # Check if n is an integer and the key is correctly positioned in the AP
    return n.is_integer()

# Example usage:
a1 = 5
a2 = 8
a3 = 11
key = 20

if is_key_in_ap(a1, a2, a3, key):
    print(f"The key {key} is present in the AP.")
else:
    print(f"The key {key} is not present in the AP.")
