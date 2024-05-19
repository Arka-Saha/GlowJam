import promidi.*;
import processing.serial.*;

//Defining variables
Serial myport;
MidiIO midiIO;

void setup()
{
  myport = new Serial(this, "COM7", 9600);
  midiIO = MidiIO.getInstance(this);
  midiIO.printDevices(); //prints avaliable devices including midis
  midiIO.openInput(0,0); //opens the required channel having desired device
}

void draw(){}

void noteOn(Note note, int deviceNum, int midiChan)
{
  int vel = note.getVelocity();
  int pitch = note.getPitch();
  myport.write(pitch); //sends pitch data to arduino via port/serial communication
  println(pitch);
}
