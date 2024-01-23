#include <iostream>
#include <cmath>

// Constants
const double fR = 16.35;  // Reference frequency for note C in the "zeroth" octave
const double c = 345.0;   // Speed of sound in air (in m/s)

// Function to compute the frequency
double computeFrequency(int v, int k) {
    return fR * pow(2.0, v + static_cast<double>(k) / 12.0);
}

// Function to compute the wavelength
double computeWavelength(double f_kv) {
    return c / f_kv;
}

int main() {
    int v, k;

    // Get user input for octave and half-step
    std::cout << "Enter the octave (0 to 8): ";
    std::cin >> v;
    std::cout << "Enter the half-step (0 to 11): ";
    std::cin >> k;

    // Compute frequency and wavelength
    double f_kv = computeFrequency(v, k);
    double W_kv = computeWavelength(f_kv);

    // Display results
    std::cout << "Frequency: " << f_kv << " Hz" << std::endl;
    std::cout << "Wavelength: " << (W_kv * 100) << " cm" << std::endl; // converting to centimeters

    return 0;
}