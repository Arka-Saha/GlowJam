import promidi.*;

import processing.serial.*;

Serial myport;
MidiIO midiIO;

void setup()
{
  myport = new Serial(this, "COM7", 9600);
  midiIO = MidiIO.getInstance(this);
  midiIO.printDevices();
  midiIO.openInput(0,0);
}

void draw(){}

void noteOn(Note note, int deviceNum, int midiChan)
{
  int vel = note.getVelocity();
  int pitch = note.getPitch();
  myport.write(pitch);
  println(pitch);
}

