#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "chords.h"
#include <stdint.h> //touchscreen
#include "TouchScreen.h"
// These are the pins for the touchscreen
#define YP A6  // must be an analog pin, use "An" notation!
#define XM A7  // must be an analog pin, use "An" notation!
#define YM 8   // can be a digital pin
#define XP 9   // can be a digital pin
#define TsPot1 A18 // 
#define TsPot2 A19 // 
#define selectionPin A20 // 
//SD CARD MOSI_PIN 7 & SCK_PIN 14  CS_PIN?
//Bounce buttonA = Bounce(10, 8); // pin,debouncetime
//use pinMode(10, INPUT_PULLUP); for buttons
//if(buttonA.fallingEdge()) { }
int Pot1 = 0;
int Pot2 = 0;
int selectionValue = 0;
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 370);  //use a multimeter to read the resistance between X+ and X- and replace value which is currently 300.


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
}

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform4;      //xy=224.44445037841797,1697.7775182724
AudioSynthWaveform       waveform6;      //xy=234.44445037841797,1786.3489468438286
AudioSynthWaveform       waveform5;      //xy=241.58730752127508,1739.2060897009712
AudioSynthWaveform       waveform8;      //xy=320.9523391723633,1967.7777099609375
AudioSynthWaveform       waveform3;      //xy=323.8094902038574,1930.634804725647
AudioSynthWaveform       waveform1;      //xy=334.28568267822266,1840.1583137512207
AudioSynthWaveform       waveform2;      //xy=335.2380599975586,1876.349126815796
AudioMixer4              mixer4;         //xy=370.7936553955078,1742.5394973754883
AudioPlaySdRaw           playSdRaw1;     //xy=428.57147216796875,2072.8571166992188
AudioMixer4              mixer7;         //xy=493.6507453918457,1952.3808784484863
AudioMixer4              mixer3;         //xy=502.2221984863281,1878.09499168396
AudioEffectFade          fade2;          //xy=544.4443893432617,1759.999948501587
AudioEffectDelay         delay2;         //xy=625.714298248291,2087.1429405212402
AudioEffectFade          fade1;          //xy=657.7777900695801,1893.3333549499512
AudioEffectFade          fade3;          //xy=663.3333333333334,1943.3333333333333
AudioSynthKarplusStrong  string2;        //xy=687.1428680419922,1687.1428985595703
AudioSynthKarplusStrong  string1;        //xy=690.000114440918,1651.4286136627197
AudioEffectEnvelope      envelope2;      //xy=714.2857284545898,1758.5711965560913
AudioSynthWaveform       waveform7;      //xy=737.1428871154785,1824.2854919433594
AudioEffectEnvelope      envelope1;      //xy=818.5712966918945,1914.285478591919
AudioEffectEnvelope      envelope3;      //xy=818.5713577270508,1962.8570098876953
AudioMixer4              mixer2;         //xy=824.4444427490234,2136.6668548583984
AudioMixer4              mixer8;         //xy=831.4286651611328,2054.2855224609375
AudioMixer4              mixer6;         //xy=838.5714416503906,1671.428560256958
AudioFilterStateVariable filter2;        //xy=848.5713664463589,1765.7142105102541
AudioEffectBitcrusher    bitcrusher1;    //xy=997.1429159981865,1671.428457123893
AudioMixer4              mixer12;        //xy=1005.7143898010254,1775.7142391204834
AudioMixer4              mixer11;        //xy=1008.5713806152344,1939.9998168945312
AudioMixer4              mixer10;        //xy=1010.0001068115234,2054.28564453125
AudioMixer4              mixer9;         //xy=1126.9842910766602,1711.428409576416
AudioMixer4              mixer1;         //xy=1233.809440612793,1818.7300548553467
AudioOutputI2S           i2s1;           //xy=1272.2221755981445,1933.3333835601807
AudioConnection          patchCord1(waveform4, 0, mixer4, 0);
AudioConnection          patchCord2(waveform6, 0, mixer4, 2);
AudioConnection          patchCord3(waveform5, 0, mixer4, 1);
AudioConnection          patchCord4(waveform8, 0, mixer7, 2);
AudioConnection          patchCord5(waveform3, 0, mixer7, 1);
AudioConnection          patchCord6(waveform1, 0, mixer3, 1);
AudioConnection          patchCord7(waveform2, 0, mixer3, 2);
AudioConnection          patchCord8(mixer4, fade2);
AudioConnection          patchCord9(playSdRaw1, delay2);
AudioConnection          patchCord10(mixer7, fade3);
AudioConnection          patchCord11(mixer3, fade1);
AudioConnection          patchCord12(fade2, envelope2);
AudioConnection          patchCord13(delay2, 0, mixer8, 0);
AudioConnection          patchCord14(delay2, 1, mixer8, 1);
AudioConnection          patchCord15(delay2, 2, mixer8, 2);
AudioConnection          patchCord16(delay2, 3, mixer8, 3);
AudioConnection          patchCord17(delay2, 4, mixer2, 0);
AudioConnection          patchCord18(delay2, 5, mixer2, 1);
AudioConnection          patchCord19(delay2, 6, mixer2, 2);
AudioConnection          patchCord20(delay2, 7, mixer2, 3);
AudioConnection          patchCord21(fade1, envelope1);
AudioConnection          patchCord22(fade3, envelope3);
AudioConnection          patchCord23(string2, 0, mixer6, 1);
AudioConnection          patchCord24(string1, 0, mixer6, 0);
AudioConnection          patchCord25(envelope2, 0, filter2, 0);
AudioConnection          patchCord26(waveform7, 0, filter2, 1);
AudioConnection          patchCord27(envelope1, 0, mixer11, 1);
AudioConnection          patchCord28(envelope3, 0, mixer11, 2);
AudioConnection          patchCord29(mixer2, 0, mixer10, 2);
AudioConnection          patchCord30(mixer8, 0, mixer10, 1);
AudioConnection          patchCord31(mixer6, bitcrusher1);
AudioConnection          patchCord32(filter2, 0, mixer12, 0);
AudioConnection          patchCord33(filter2, 1, mixer12, 1);
AudioConnection          patchCord34(filter2, 2, mixer12, 2);
AudioConnection          patchCord35(bitcrusher1, 0, mixer9, 2);
AudioConnection          patchCord36(mixer12, 0, mixer1, 1);
AudioConnection          patchCord37(mixer11, 0, mixer1, 2);
AudioConnection          patchCord38(mixer10, 0, mixer1, 3);
AudioConnection          patchCord39(mixer9, 0, mixer1, 0);
AudioConnection          patchCord40(mixer1, 0, i2s1, 0);
AudioConnection          patchCord41(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     audioShield;     //xy=1220.793601989746,2004.1269540786743
// GUItool: end automatically generated code



void setup() {
  // put your setup code here, to run once:
  AudioMemory(100);  //each block = 3ms and max delay is 425ms..
  audioShield.enable();
  audioShield.volume(0.5);  //what is autoVolumeControl(x,x,x,x,x,x); and audioPostProcessorEnable();? from bitcrusher example
  mixer1.gain(0, 1);  // main mixer(channel0-3,level0-32767)
  mixer1.gain(1, 1);
  mixer1.gain(2, 1);
  mixer1.gain(3, 1);
  
  //mixer2.gain(0, 1);
  mixer3.gain(0, 1);
  mixer3.gain(1, 1);
  mixer3.gain(2, 1);
  mixer3.gain(3, 1);

  mixer4.gain(0, 1);
  mixer4.gain(1, 1);
  mixer4.gain(2, 1);
  mixer4.gain(3, 1);
  
 // mixer5.gain(0, 1);
  mixer6.gain(0, 1);
  mixer6.gain(1, 1);
  mixer6.gain(2, 1);
  mixer6.gain(3, 1);

  mixer7.gain(0, 1);
  mixer7.gain(1, 1);
  mixer7.gain(2, 1);
  mixer7.gain(3, 1);

  mixer8.gain(0, 1);
  mixer8.gain(1, 1);
  mixer8.gain(2, 1);
  mixer8.gain(3, 1);

  //mixer9.gain(0, 1);
  //mixer10.gain(0, 1);
  //mixer11.gain(0, 1);
  //mixer12.gain(0, 1);

  SPI.setMOSI(7);
  SPI.setSCK(14);
 // if (!(SD.begin(10))) { //print error message 
  //  while(1) {
  //    Serial.println("nope");
    //delay(500); }//remove this delay before code is finalized.
    
  //}

}

void loop() {
  do_right_panel();
}
void do_right_panel(void)  // touch panel synth stuff goes here
{  
 Pot1 = analogRead(TsPot1);
 Pot2 = analogRead(TsPot2);
 selectionValue = analogRead(selectionPin);  //this is used to select the different synth options in lieu of a button/rotary interaface.  
 TSPoint p = ts.getPoint();    // a point object holds x y and z coordinates
  
 // if (p.z > ts.pressureThreshhold) {  //we have some minimum pressure we consider 'valid' .... pressure of 0 means no pressing!
   //need to calibrate this so it always registers when pressed...
     //Serial.print("Pot1 = "); Serial.print(Pot1);
     //Serial.print("Pot2 = "); Serial.print(Pot2);
     //Serial.print("selectionValue = ");  Serial.println(selectionValue);
     Serial.print("RawX = "); Serial.print(p.x); //64-900
     Serial.print("RawY = "); Serial.print(p.y); //60-590 center value when not being touched.
     //Serial.print("\tPressure = "); Serial.println(p.z);
  //}
//piano freq range 27.5 Hz (A0) to 4186 Hz (C8)

  int constX = constrain(p.x, 60, 950); 
  int mappedX = map(constX, 60, 950, 28, 3186);  //
  Serial.print ("mappedX = "); Serial.print(mappedX); 

  int constY = constrain(p.y, 97, 910);
  int mappedY = map(constY, 97, 910, 28, 3186);   
  Serial.print ("mappedY = "); Serial.println(mappedY); 

delay(100);
    if (selectionValue > 0 && selectionValue < 256){ //guitar w/ distortion patch: string1&2 > bitcrusher1
      //noteOn(frequency, velocity(0-1)); noteOff(velocity); //bits(xcrushBits(1-16)); 16=clean sampleRate(xsampleRate); 
      mixer9.gain(2, 1); 
      mixer9.gain(0, 1);
      mixer9.gain(1, 1);
      mixer9.gain(3, 1);
      bitcrusher1.bits(16);  
      bitcrusher1.sampleRate(44100);
       if (p.x > 60){                      //X
          Serial.print("nowTouching  ");
           if (p.x > 60 && p.x < 356){
           string1.noteOn(NOTE_C3, 1);  //C3
           Serial.print("C3"); }
              if (p.x > 357 && p.x < 600){
              string1.noteOn(NOTE_G3, 1);  //G3
              Serial.print("G3"); }
                if (p.x > 601 && p.x < 356){
                string1.noteOn(NOTE_C4, 1);  //C4
                Serial.print("C4"); }
                 if (p.y > 60 && p.y < 300 ); {    //Y defaults to ~195 when not being touched...
                 string2.noteOn(NOTE_E3, 1); 
                 Serial.print("E3"); }
            }      if (p.y > 301 && p.y < 600 ); {
                   string2.noteOn(NOTE_E4, 1);
            }
          
    }
      
      
     else if (selectionValue > 257 && selectionValue < 512){ //waveform LPF & HPF mixer: waveform4,5,6 > envelope2 > filter2 w/ waveform7 input >
      mixer12.gain(0,1);  //set gain for other channels
      
      //waveformX3.begin(level, freq, WAVEFORM_SINE);
      //waveformX.frequency(freq);
      //waveformX.pulseWidth(amount); ??

      //remove fade and envelope

      
      //filterY.frequency(freq); corner freq when input control signal is zero
      //filterY.resonance(Q); .7 - 5.0 attenuate beforehand to prevent clipping
      //filterY.octaveControl(octaves); 0-7 octave range. sets attenuation range for filters corner frequency.  
      //waveformX.begin(level, freq, WAVEFORM_SINE);
      //waveformX.frequency(freq);

      
    } else if (selectionValue > 513 && selectionValue< 768){  //waveform chord mixer waveform 1&2 > envelope1 > out
      mixer11.gain(0,1); //set gain for other channels;
      //waveform8&3 > mixer7 > fade3 > env3...waveform1&2 > mixer3 > fade1 > env1
     
     if (p.x > 60){ //begin playing when touched
     waveform8.begin(1.0, 130.81, WAVEFORM_SINE); //C3
     waveform3.begin(1.0, 261.63, WAVEFORM_TRIANGLE); //C4
     waveform8.frequency(mappedX);
     waveform3.frequency(mappedX);
     //fade and envelope
     fade3.fadeIn(500);
     envelope3.noteOn();
     envelope3.delay(0);
     envelope3.hold(0);
     waveform1.begin(1.0, 196.00, WAVEFORM_SQUARE); //G3
     waveform2.begin(1.0, 392.00, WAVEFORM_TRIANGLE); //G4
     waveform1.frequency(mappedY);
     waveform2.frequency(mappedY);
      //fade and envelope
     fade1.fadeIn(500);
     envelope1.noteOn();
     envelope1.delay(0);
     envelope1.hold(0);
      //remove fade and/or envelope

    
     }
    
    } else {  //playSDRaw1 > delay2 (x8) > mixer1
      mixer10.gain(0,1);  //set gain for other channels
      //SDraw
      //if(p.x > 60){  playSDRaw1.play("filename.raw");  }
      //if(p.x < 60){ playSDRaw1.stop();  }
      //lengthMillis(); can you retrigger the wav file with the touchscreen?

      //delayY1-8.delay(channel0-7, milliseconds);  //max 425mS...how much AudioMemory() needed?  each block = 3mS of delay
      }
}

