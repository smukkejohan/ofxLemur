
#pragma once
#include "ofxXmlSettings.h"


/*
 Setup with ports
 
 Osc receive and send automaticly setup ?
 Variable binding ?
 
 Outputs an xml interface.
 
 */



class ofxLemurBaseObject {
    
public:
    string name;
    int x;
    int y;
    int w;
    int h;
    
    virtual void saveXml(ofxXmlSettings * xml, int i) {
        xml->pushTag("WINDOW");
        
        xml->popTag();
    }
    
};


class ofxLemurInterface {
public:
    ofxLemurInterface(string _name) {
        name = _name;
    };
    ~ofxLemurInterface();
    
    string name;
    vector<ofxLemurBaseObject *> objects;
};

class ofxLemurFader : public ofxLemurBaseObject {
public:
    
    float x;
    float y;
    
    int precision = 3;
    bool showValue = true;
    bool label = true;
    string unit;
    
    // Behavior
    // cursor mode
    // physics
    string attraction;
    string friction;
    string speed;
    bool capture;
    bool constrainToGrid;
    int gridSteps;
    
    void saveXml(ofxXmlSettings * xml, int i) {
        xml->pushTag("WINDOW");
        
        xml->popTag();
    }

    
    
    /* EXAMPLE XML
    <WINDOW class="Fader" text="Fader" x="38" y="27" width="152" height="486" id="1" state="1" group="0" font="tahoma,10,0" send="1" osc_target="0" midi_target="-2" kbmouse_target="-2" capture="1" color="1596013" cursor="0" grid="0" grid_steps="1" label="1" physic="1" precision="3" unit="hm" value="1" zoom="0.000000">
    <PARAM name="x=" value="0.000000" send="17" osc_target="0" osc_trigger="1" osc_message="/Fader/x" midi_target="-1" midi_trigger="1" midi_message="0x90,0x90,0,0" midi_scale="0,16383" osc_scale="0.000000,1.000000" kbmouse_target="-1" kbmouse_trigger="1" kbmouse_message="0,0,0" kbmouse_scale="0,1,0,1"/>
    <PARAM name="z=" value="0.000000" send="17" osc_target="0" osc_trigger="1" osc_message="/Fader/z" midi_target="-1" midi_trigger="1" midi_message="0x90,0x90,0,0" midi_scale="0,16383" osc_scale="0.000000,1.000000" kbmouse_target="-1" kbmouse_trigger="1" kbmouse_message="0,0,0" kbmouse_scale="0,1,0,1"/>
    <VARIABLE name="value=x" send="0" osc_target="0" osc_trigger="1" osc_message="/Fader/value" midi_target="-1" midi_trigger="1" midi_message="0x90,0x90,0,0" midi_scale="0,16383" kbmouse_target="-1" kbmouse_trigger="1" kbmouse_message="0,0,0" kbmouse_scale="0,1,0,1"/>
    <VARIABLE name="attraction=1" send="0" osc_target="0" osc_trigger="1" osc_message="/Fader/attraction" midi_target="-1" midi_trigger="1" midi_message="0x90,0x90,0,0" midi_scale="0,16383" kbmouse_target="-1" kbmouse_trigger="1" kbmouse_message="0,0,0" kbmouse_scale="0,1,0,1"/>
    <VARIABLE name="friction=0.9" send="0" osc_target="0" osc_trigger="1" osc_message="/Fader/friction" midi_target="-1" midi_trigger="1" midi_message="0x90,0x90,0,0" midi_scale="0,16383" kbmouse_target="-1" kbmouse_trigger="1" kbmouse_message="0,0,0" kbmouse_scale="0,1,0,1"/>
    <VARIABLE name="speed=1" send="0" osc_target="0" osc_trigger="1" osc_message="/Fader/speed" midi_target="-1" midi_trigger="1" midi_message="0x90,0x90,0,0" midi_scale="0,16383" kbmouse_target="-1" kbmouse_trigger="1" kbmouse_message="0,0,0" kbmouse_scale="0,1,0,1"/>
    </WINDOW>*/
    
};


class ofxLemurProject {
    
public:
    
    ofxLemurProject(){};
    ~ofxLemurProject(){};
    
    //void load();
    void save();
    
    ofxXmlSettings xml;
    vector<ofxLemurInterface *> interfaces;
    

    
    
    
};


