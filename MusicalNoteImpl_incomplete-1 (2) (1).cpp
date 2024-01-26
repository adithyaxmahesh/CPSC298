#include "MusicalNoteApi.h"  // Include the header file

// Constants and definitions (assuming these are defined in MusicalNoteApi.h)
const double k_dFrequencyRef = 440.0;  // Reference frequency in Hz
const int k_nHalfTonesInOctave = 12;   // Number of halftones in an octave
const double k_SpeedOfSoundCmPerSec = 34300.0;  // Speed of sound in cm/sec

double computeFrequency(int nu, int k) {
    double f = -1.0; 
    if ((k >= 0) && (k < 12) && (nu >= 0)) {
        f = k_dFrequencyRef * pow(2.0, nu + (k / 12.0));  // Frequency calculation
    } else {
        std::cerr << "ERROR: computeFrequency preconditions not satisfied; nu (" << nu << ") or k (" << k << ") invalid" << std::endl;
    }
    return f;
}

double computeWavelengthInCm(double dFrequencyHz) {
    double dWavelengthCm = -1.0; 
    if ((dFrequencyHz > 0.0) && std::isfinite(dFrequencyHz)) {
        dWavelengthCm = (k_SpeedOfSoundCmPerSec / dFrequencyHz) * 100;  // Wavelength calculation
    } else {
        std::cerr << "ERROR: computeWavelengthInCm preconditions not satisfied; dFrequencyHz invalid: " << dFrequencyHz << std::endl;
    }
    return dWavelengthCm;
}

const std::string getNoteName(int nu, int k) {
    const static std::string a_strNotePrefix[] = {
        "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
    };
    std::string strNote = "UNK";
    if ((k >= 0) && (k < k_nHalfTonesInOctave) && (nu >= 0)) {
        strNote = a_strNotePrefix[k] + std::to_string(nu);  // Constructing note name
    }
    return strNote; 
}

int main() {
    int nOctaves = 11;  // Number of octaves over which to compute frequencies

    for (int nu = 0; nu < nOctaves; nu++) {
        for (int k = 0; k < k_nHalfTonesInOctave; k++) {
            double f = computeFrequency(nu, k);
            double dWavelengthCentimeters = computeWavelengthInCm(f);
            std::string strNote = getNoteName(nu, k);

            std::cout << "Note: " << strNote << "; nu: " << nu << "; k: " << k << "; frequency: " << f << " Hz; wavelength: " << dWavelengthCentimeters << " cm" << std::endl;
        }
    }

    // Error handling test
    double f = computeFrequency(-1, -1);
    double dWavelengthCentimeters = computeWavelengthInCm(-16.35);
    std::string strNote = getNoteName(-1, -1);

    std::cout << "Note: " << strNote << "; nu: -1; k: -1; frequency: " << f << " Hz; wavelength: " << dWavelengthCentimeters << " cm" << std::endl;

    return 0;
}
