#include <iostream>
#include <cmath>

int main() {
    const double fR = 16.35; // Reference Frequency in Hz
    const double speedOfSound = 34500; // Speed of sound in cm/s
    const int maxOctaves = 9; // Octave range from 0 to 8
    const int halfSteps = 12; // Half-steps in an octave

    double frequencies[maxOctaves][halfSteps];
    double wavelengths[maxOctaves][halfSteps];

    // Compute frequencies and wavelengths for each octave and half-step
    for (int nu = 0; nu < maxOctaves; ++nu) {
        for (int k = 0; k < halfSteps; ++k) {
            double frequency = fR * pow(2, nu + (k / 12.0));
            frequencies[nu][k] = frequency;
            wavelengths[nu][k] = speedOfSound / frequency;

            // Display the results
            std::cout << "Octave: " << nu << ", Half-step: " << k 
                      << ", Frequency: " << frequencies[nu][k] << " Hz"
                      << ", Wavelength: " << wavelengths[nu][k] << " cm" << std::endl;
        }
    }

    return 0;
}
