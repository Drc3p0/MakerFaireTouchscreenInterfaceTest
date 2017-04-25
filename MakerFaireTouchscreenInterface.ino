#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <stdint.h> //touchscreen
#include "TouchScreen.h"
// These are the pins for the touchscreen
#define YP A3  // must be an analog pin, use "An" notation!
#define XM A4  // must be an analog pin, use "An" notation!
#define YM 8   // can be a digital pin
#define XP 9   // can be a digital pin
#define TsPot1 A5 // 
#define TsPot2 A6 // 
#define selectionPin A7 // 

int TsPot1Val = 0;
int TsPot2Val = 0;
int selectionValue = 0;
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);  //use a multimeter to read the resistance between X+ and X- and replace value which is currently 300.


elapsedMillis sinceTempo;
int tempo = 120;
int stepCount;

// MIDI SCALES 
int dorian[8] = {0, 2, 3, 5, 7, 9, 10, 12};  // dorian 
int majorPentatonic[8] = {0, 2, 4, 7, 9, 12, 14, 16};  // major pentatonic
int minorPentatonic[8] = {0, 3, 5, 7, 10, 12, 15, 17}; // minor pentatonic 
int octaves[5] = {0, 12, 24, 36, 48}; // octaves
float mtof(int note){      // Outputs a float freq based on incoming MIDI note. How to use: mtof(noteValue)  
   return (440.0f * exp2f((float)(note - 69) * 0.0833333f));

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform4;      //xy=340.0000114440918,1699.9997282028198
AudioSynthWaveform       waveform6;      //xy=350.0000114440918,1788.5711567742485
AudioSynthWaveform       waveform5;      //xy=357.1428685869489,1741.4282996313912
AudioPlaySdRaw           playSdRaw1;     //xy=428.57147216796875,2072.8571166992188
AudioSynthWaveform       waveform8;      //xy=494.28564834594727,1989.9999551773071
AudioSynthWaveform       waveform3;      //xy=497.1427993774414,1952.8570499420166
AudioSynthWaveform       waveform1;      //xy=507.61899185180664,1862.3805589675903
AudioSynthWaveform       waveform2;      //xy=508.5713691711426,1898.5713720321655
AudioMixer4              mixer4;         //xy=518.5714329310825,1751.4283688408989
AudioEffectDelay         delay2;         //xy=625.714298248291,2087.1429405212402
AudioMixer4              mixer7;         //xy=661.428466796875,1965.7141723632812
AudioMixer4              mixer3;         //xy=669.9999198913574,1891.4282855987549
AudioEffectEnvelope      envelope2;      //xy=674.2857219151089,1758.5711660385134
AudioSynthKarplusStrong  string2;        //xy=687.1428680419922,1687.1428985595703
AudioSynthKarplusStrong  string1;        //xy=690.000114440918,1651.4286136627197
AudioSynthWaveform       waveform7;      //xy=737.1428871154785,1824.2854919433594
AudioEffectEnvelope      envelope1;      //xy=818.5712966918945,1914.285478591919
AudioEffectEnvelope      envelope3;      //xy=818.5713577270508,1962.8570098876953
AudioMixer4              mixer8;         //xy=831.4286651611328,2054.2855224609375
AudioMixer4              mixer9;         //xy=831.4286880493164,2121.4284133911133
AudioMixer4              mixer6;         //xy=838.5714416503906,1671.428560256958
AudioFilterStateVariable filter2;        //xy=848.5713664463589,1765.7142105102541
AudioEffectBitcrusher    bitcrusher1;    //xy=997.1429159981865,1671.428457123893
AudioMixer4              mixer12;        //xy=1005.7143898010254,1775.7142391204834
AudioMixer4              mixer11;        //xy=1008.5713806152344,1939.9998168945312
AudioMixer4              mixer10;        //xy=1010.0001068115234,2054.28564453125
AudioMixer4              mixer1;         //xy=1197.1427993774414,1864.2856464385986
AudioOutputI2S           i2s1;           //xy=1232.2221488952637,1944.4444541931152
AudioConnection          patchCord1(waveform4, 0, mixer4, 0);
AudioConnection          patchCord2(waveform6, 0, mixer4, 2);
AudioConnection          patchCord3(waveform5, 0, mixer4, 1);
AudioConnection          patchCord4(playSdRaw1, delay2);
AudioConnection          patchCord5(waveform8, 0, mixer7, 2);
AudioConnection          patchCord6(waveform3, 0, mixer7, 1);
AudioConnection          patchCord7(waveform1, 0, mixer3, 1);
AudioConnection          patchCord8(waveform2, 0, mixer3, 2);
AudioConnection          patchCord9(mixer4, envelope2);
AudioConnection          patchCord10(delay2, 0, mixer8, 0);
AudioConnection          patchCord11(delay2, 1, mixer8, 1);
AudioConnection          patchCord12(delay2, 2, mixer8, 2);
AudioConnection          patchCord13(delay2, 3, mixer8, 3);
AudioConnection          patchCord14(delay2, 4, mixer9, 0);
AudioConnection          patchCord15(delay2, 5, mixer9, 1);
AudioConnection          patchCord16(delay2, 6, mixer9, 2);
AudioConnection          patchCord17(delay2, 7, mixer9, 3);
AudioConnection          patchCord18(mixer7, envelope3);
AudioConnection          patchCord19(mixer3, envelope1);
AudioConnection          patchCord20(envelope2, 0, filter2, 0);
AudioConnection          patchCord21(string2, 0, mixer6, 1);
AudioConnection          patchCord22(string1, 0, mixer6, 0);
AudioConnection          patchCord23(waveform7, 0, filter2, 1);
AudioConnection          patchCord24(envelope1, 0, mixer11, 1);
AudioConnection          patchCord25(envelope3, 0, mixer11, 2);
AudioConnection          patchCord26(mixer8, 0, mixer10, 1);
AudioConnection          patchCord27(mixer9, 0, mixer10, 2);
AudioConnection          patchCord28(mixer6, bitcrusher1);
AudioConnection          patchCord29(filter2, 0, mixer12, 0);
AudioConnection          patchCord30(filter2, 1, mixer12, 1);
AudioConnection          patchCord31(filter2, 2, mixer12, 2);
AudioConnection          patchCord32(bitcrusher1, 0, mixer1, 0);
AudioConnection          patchCord33(mixer12, 0, mixer1, 1);
AudioConnection          patchCord34(mixer11, 0, mixer1, 2);
AudioConnection          patchCord35(mixer10, 0, mixer1, 3);
AudioConnection          patchCord36(mixer1, 0, i2s1, 0);
AudioConnection          patchCord37(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     audioShield;     //xy=1220.793601989746,2004.1269540786743
// GUItool: end automatically generated code



void setup() {
  // put your setup code here, to run once:
  AudioMemory(1200);  //each block = 3ms and max delay is 425ms..
  audioShield.enable();
  audioShield.volume(0.5);  //what is autoVolumeControl(x,x,x,x,x,x); and audioPostProcessorEnable();? from bitcrusher example
  mixer1.gain(0, 1);  //(channel0-3,level0-32767)
  mixer2.gain(0, 1);
  mixer3.gain(0, 1);
  mixer4.gain(0, 1);
  mixer5.gain(0, 1);
  mixer6.gain(0, 1);
  mixer7.gain(0, 1);
  mixer8.gain(0, 1);
  mixer9.gain(0, 1);
  mixer10.gain(0, 1);
  mixer11.gain(0, 1);
  mixer12.gain(0, 1);

  SPI.setMOSI(7);
  SPI.setSCK(14);
  if (!(SD.begin(10))) { //print error message 
    while(1) {
      Serial.println("SD card no worky");
    delay(500); //remove this delay before code is finalized.
    }
  }

}

void loop() {
  do_right_panel();

void do_right_panel(void);  // touch panel synth stuff goes here
{  
 TsPot1Val = analogRead(TsPot1);
 TsPot2Val = analogRead(TsPot2);
 selectionValue = analogRead(selectionPin);
 TSPoint p = ts.getPoint();    // a point object holds x y and z coordinates
  
  if (p.z > ts.pressureThreshhold) {  //we have some minimum pressure we consider 'valid' .... pressure of 0 means no pressing!
     Serial.print("X = "); Serial.print(p.x);
     Serial.print("\tY = "); Serial.print(p.y);
     Serial.print("\tPressure = "); Serial.println(p.z);
  }
  //remove when done testing..
  Serial.print("Pot1Val = ");  Serial.print(TsPot1Val);
  Serial.print("Pot2Val = ");  Serial.print(TsPot2Val);
  Serial.print("Pot3Val = ");  Serial.println(TsPot3Val);

    if (selectionValue > 0 && < 256){ //guitar w/ distortion patch: string1&2 > bitcrusher1
      //noteOn(frequency, velocity(0-1)); noteOff(velocity); //bits(xcrushBits(1-16)); 16=clean sampleRate(xsampleRate); 
      
    } else if (selectionValue > 257 && < 512){ //waveform LPF & HPF mixer: waveform4,5,6 > envelope2 > filter2 w/ waveform7 input >

    } else if (selectionValue > 513 && < 768){  //waveform chord mixer waveform 1&2 > envelope1 > out

    } else {  //playSDRaw1 > delay2 (x8) > mixer1
      
      }
}
