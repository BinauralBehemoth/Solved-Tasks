/*
 * Repetitions
 *
 * You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is
 * to find the longest repetition in the sequence. This is a maximum-length substring containing
 * only one type of character.
 *
 * Input
 * The only input line contains a string of n characters.
 *
 * Output
 * Print one integer: the length of the longest repetition.
 *
 * Constraints
 * 1≤n≤106
 *
 * Example
 *
 * Input:
 * ATTCGGGA
 *
 * Output:
 * 3
 */


#include <iostream>
#include <string>

int main() {

	std::string dna;
	int maxRepetition = 1;
	std::cin >> dna;

	/*
	 * Checking each character of dna if it's repetition start character.
	 * There is no point to check chacrters after dna.size() - 1 - maxRepetitions, because if it even
	 * will be only repetition through the end of dna, length of that repetition won't be more than maxRepetition.
	 * It's needed to use (int)dna.size(), beacause string.size() has unsigned int type, so in cases when
	 * dna.size() < 1 + maxRepetition, it turns into huge number instead of becoming negative.
	 */
	for (int i = 0; i <= (int)dna.size() - 1 - maxRepetition; i++) {
		
		// cheking if it's start of repetition
		if (dna[i] == dna[i + 1]) {

			int currentLength = 2;
			bool keepLoop = true;

			// calculating length of current repetition
			while (keepLoop) {
				if (i + currentLength <= dna.size() - 1) {
					if (dna[i + currentLength] == dna[i]) {
						currentLength++;
					}
					else {
						keepLoop = false;
					}
				}
				else {
					keepLoop = false;
				}
			}

			if (currentLength > maxRepetition) {
				maxRepetition = currentLength;
			}

			// there is no point to check next characters of repetition, because it will be similar
			// repetitions but with smaller length
			i += currentLength - 1;
		}
	}

	std::cout << maxRepetition;

	return 0;
}