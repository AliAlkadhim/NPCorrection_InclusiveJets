// Headers and Namespaces.
#include "Pythia8/Pythia.h" // Include Pythia headers.
using namespace Pythia8;
// Let Pythia8:: be implicit.
int main() {
// Set up generation.
Pythia pythia;
Hist pT("transverse momentum", 100, 0., 200.);

// Declare Pythia object
pythia.readString("Top:gg2ttbar = on"); // Switch on process.
pythia.readString("Beams:eCM = 8000."); // 8 TeV CM energy.
// pythia.readString("Next:numberShowEvent = 5");
pythia.init(); // Initialize; incoming pp beams is default.
// Generate 5 events.
for (int iEvent=0; iEvent < 5; ++iEvent) {

pythia.next(); // Generate an(other) event. Fill event record.
 //START PARTICLE LOOP
 for (int i = 0; i < pythia.event.size(); ++i) {
     
     pT.fill( pythia.event[i].pT());
}
cout << pT;
}
return 0;
}
