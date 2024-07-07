with open('17-304.txt', 'r') as file:
    sequence = list(map(int, file.read().split()))

max_element = max(sequence)
pairs_count = 0
sum_of_pairs = 0

for i in range(len(sequence) - 1):
    hex1 = hex(sequence[i])[2:]  
    hex2 = hex(sequence[i+1])[2:]
    if ('AA' in hex1) and ('AA' in hex2) and (sequence[i] + sequence[i+1] < max_element) and (max_element % 246 == 0):
        pairs_count += 1
        sum_of_pairs += sequence[i] + sequence[i+1]

print(pairs_count)
print(sum_of_pairs)