
bool haveOppositeSigns(int a, int b) {
    return (a ^ b) < 0;  // XOR operation checks the sign bit
}