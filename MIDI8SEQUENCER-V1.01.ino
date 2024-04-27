#include <MIDI.h>

// Define the number of LEDs and their connected pins
#define NUM_OF_LEDS 8
int PIN_LED[NUM_OF_LEDS] = {2, 3, 4, 5, 6, 7, 8, 9};

// Define pins for potentiometers and button
#define PIN_CLOCK_POT A0
#define PIN_STEP_POT A1
#define BUTTON_PIN 10

// Define clock divisions for BPM adjustments
#define NUM_OF_CLOCK_DIVISIONS 5
int clock_division[] = {1, 3, 6, 12, 24};

// Sequencer state variables
int clock_counter = 0;
int step_counter = 0;
int play_mode = 0;
bool is_playing = false;
bool pingpong_direction = true;

// MIDI handling setup
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
    for (int i = 0; i < NUM_OF_LEDS; i++) {
        pinMode(PIN_LED[i], OUTPUT);
    }
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    MIDI.begin(MIDI_CHANNEL_OMNI);
    MIDI.setHandleClock(message_clock);
    MIDI.setHandleStart(message_start);
    MIDI.setHandleStop(message_stop);
}

void loop() {
    MIDI.read();

    static bool lastButtonState = HIGH;
    bool buttonState = digitalRead(BUTTON_PIN);

    if (lastButtonState != buttonState && buttonState == LOW) {
        if (is_playing) {
            play_mode = (play_mode + 1) % 4;
            if (play_mode == 2) pingpong_direction = true;
        } else {
            step_counter = (step_counter + 1) % NUM_OF_LEDS;
            light_up_current_step();
        }
    }

    lastButtonState = buttonState;
}

void message_clock() {
    int step_pot_value = analogRead(PIN_STEP_POT);
    int step_pot_mapped = map(step_pot_value, 0, 1023, 1, NUM_OF_LEDS);
    int clock_pot_value = analogRead(PIN_CLOCK_POT);
    int clock_pot_mapped = map(clock_pot_value, 0, 1023, NUM_OF_CLOCK_DIVISIONS - 1, 0);
    int clock_pot_selected = clock_division[clock_pot_mapped];

    if (clock_counter % clock_pot_selected == 0) {
        if (is_playing) {
            switch (play_mode) {
                case 1: // Reverse
                    step_counter = (step_counter - 1 + step_pot_mapped) % step_pot_mapped;
                    break;
                case 2: // Ping-Pong
                    step_counter += (pingpong_direction ? 1 : -1);
                    if (step_counter >= step_pot_mapped - 1 || step_counter <= 0)
                        pingpong_direction = !pingpong_direction;
                    step_counter = constrain(step_counter, 0, step_pot_mapped - 1);
                    break;
                case 3: // Random
                    step_counter = random(0, step_pot_mapped);
                    break;
                default: // Forward
                    step_counter = (step_counter + 1) % step_pot_mapped;
                    break;
            }
        }
        light_up_current_step();
    }
    clock_counter++;
}

void message_start() {
    is_playing = true;
    step_counter = 0;
    clock_counter = 0;
    pingpong_direction = true;
    light_up_current_step();
}

void message_stop() {
    is_playing = false;
    for (int i = 0; i < NUM_OF_LEDS; i++) {
        digitalWrite(PIN_LED[i], LOW); // Turn off all LEDs
    }
}

void light_up_current_step() {
    for (int i = 0; i < NUM_OF_LEDS; i++) {
        digitalWrite(PIN_LED[i], (i == step_counter) ? HIGH : LOW);
    }
}
