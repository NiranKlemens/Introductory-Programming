#include <stdio.h>  
#include <string.h>

float count_sentence(char[], float);
float count_word(char[], float);
float count_other(char[],float);
float calculation(char[]);//declare the self-defined func.

int main() {

	char text0[100] = "I like cats. Cats like me. Miao miao miao. Dogs are bad. Bad dogs bad.";
	char text1[500] = "Tomorrow, and tomorrow, and tomorrow, Creeps in this petty pace from day to day, To the last syllable of recorded time; And all our yesterdays have lighted fools The way to dusty death. Out, out, brief candle. Life's but a walking shadow, a poor player That struts and frets his hour upon the stage And then is heard no more. It is a tale Told by an idiot, full of sound and fury Signifying nothing.";
	char text2[1000] = "Existing computer programs that measure readability are based largely upon subroutines which estimate number of syllables, usually by counting vowels. The shortcoming in estimating syllables is that it necessitates keypunching the prose into the computer. There is no need to estimate syllables since word length in letters is a better predictor of readability than word length in syllables. Therefore, a new readability formula was computed that has for its predictors letters per hundred words and sentences per hundred words. Both predictors can be counted by an optical scanning device, and thus the formula makes it economically feasible for an organization such as the US Office of Education to calibrate the readability of all textbooks for the public school system.";

	printf("CLI0:%.2f\n", calculation(text0));
	printf("CLI1:%.2f\n", calculation(text1));
	printf("CLI2:%.2f\n", calculation(text2));

	getchar();
}//the main body,which take measures on 3 texts


float calculation(char text[]) {
	float length, space, word, sentence, character,other, CLI;
	length = strlen(text);
	word = count_word(text, length);
	space = word - 1;
	sentence = count_sentence(text, length);
	other =count_other(text,length);
	character = length - space - sentence-other;
	CLI = 5.89*character / word - 29.5*sentence / word - 15.8;
	return CLI = CLI < 1 ? 1 : CLI;
}//for each text,do a calculation respectively

float count_word(char text[], float length) {
	int i;
	float word, space = 0;
	for (i = 0;i < length;i++) {
		if (text[i] == ' ') {
			space++;
		}
	}
	return word = space+1;
}

float count_sentence(char text[], float length) {
	int i;
	float period = 0, sentence;
	for (i = 0;i < length;i++) {
		if (text[i] == '.') {
			period++;
		}
	}
	return sentence = period;
}//funcs for counting words and sentences

float count_other(char text[],float length) {
	int i;
	float other = 0;
	for (i = 0;i < length;i++) {
		if ((text[i] == '?')||(text[i] == ',')|| (text[i] == '\'') || (text[i] == ';')){
			other++;
		}
	}
	return other;
}//funcs for taking out other characters which aren't letters
