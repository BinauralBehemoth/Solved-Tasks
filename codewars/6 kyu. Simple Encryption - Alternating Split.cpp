/*
 * Simple Encryption #1 - Alternating Split
 *
 * For building the encrypted string:
 * Take every 2nd char from the string, then the other chars, that are not every 2nd char,
 * and concat them as new String.
 * Do this n times!
 *
 * Examples:
 * "This is a test!", 1 -> "hsi  etTi sats!"
 * "This is a test!", 2 -> "hsi  etTi sats!" -> "s eT ashi tist!"
 *
 * Write two methods:
 * std::string encrypt(std::string text, int n)
 * std::string decrypt(std::string encryptedText, int n)
 *
 * For both methods:
 * If the input-string is null or empty return exactly this value!
 * If n is <= 0 then return the input text.
 */


#include <string>

std::string encrypt(std::string text, int n)
{
	if (n <= 0 || text.length() <= 1) {
		return text;
	}

	for (int i = 1; i <= n; i++) {

		std::string string1 = "", string2 = "";

		for (int k = 0; k <= text.length() - 1; k += 2) {
			string1 += text[k];
		}

		for (int k = 1; k <= text.length() - 1; k += 2) {
			string2 += text[k];
		}

		text = string2 + string1;
	}

	return text;
}

std::string decrypt(std::string encryptedText, int n)
{
	if (n <= 0 || encryptedText.length() <= 1) {
		return encryptedText;
	}

	for (int i = 1; i <= n; i++) {

		int split = encryptedText.length() / 2;
		std::string string1 = encryptedText.substr(0, split);
		std::string string2 = encryptedText.substr(split, encryptedText.length() - split);
		encryptedText = "";

		for (int k = 0; k <= split; k++) {

			if (k <= string2.length() - 1) {
				encryptedText += string2[k];
			}

			if (k <= string1.length() - 1) {
				encryptedText += string1[k];
			}
		}
	}
	return encryptedText;
}
