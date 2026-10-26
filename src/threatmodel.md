# Project Threat Model

**Assets:** Wi-Fi credentials, firmware, and the gesture-recognition model and its labels.

**Threat:** Anyone with physical access to the ESP32-S3 or a copy of its flash contents may be able to extract hard-coded Wi-Fi credentials and model labels using firmware-analysis tools. Printing the password to the Serial Monitor also exposes it to anyone who can view the serial output.

**Impact:** Exposed credentials could allow unauthorized access to the Wi-Fi network or connected systems. Extracted firmware and model data could also reveal implementation details.

**Mitigations:** Do not hard-code real credentials or print secrets in production firmware. Use secure credential provisioning, restrict physical and debugging access, enable appropriate device security protections, and rotate credentials if they have been exposed. Keep firmware dumps and extracted strings out of the shared repository.

**Finding:** The test password `SuperSecret123` was recovered from the firmware flash dump using string extraction, demonstrating that hard-coded secrets can be exposed.
