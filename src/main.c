#include <string.h>
#include "pico/cyw43_arch.h"

#define SHORT_BLINK_SLEEP 250
#define LONG_BLINK_SLEEP 500

char const *word = "SOS";

char const *morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.",
    "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
    ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

void short_blink() {
	cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
	sleep_ms(SHORT_BLINK_SLEEP);
	cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
	sleep_ms(SHORT_BLINK_SLEEP);
}

void long_blink() {
	cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
	sleep_ms(LONG_BLINK_SLEEP);
	cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
	sleep_ms(LONG_BLINK_SLEEP);
}

int main() {
	if (cyw43_arch_init()) {
		perror("Failed to initialize Wifi");
		return -1;
	}

	int characters = 26;
	char morseCodeValue[128];

	for (int i = 0; i < strlen(word); i++) {
		strcat(morseCodeValue, morseCode[word[i] - 'A']);
		strcat(morseCodeValue, " ");
	}

	while (true) {
		for (int i = 0; i < strlen(morseCodeValue); i++) {
			if (morseCodeValue[i] == '.') {
				short_blink();
			} else if (morseCodeValue[i] == '-') {
				long_blink();
			} else if (morseCodeValue[i] == ' ') {
				sleep_ms(250);
			}
		}
		sleep_ms(2000);
	}
}
