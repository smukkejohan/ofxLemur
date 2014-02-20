//
//  ofxLemur.cpp
//
//  Created by Johan Bichel Lindegaard on 08/02/14.
//
//

#include "ofxLemur.h"


void ofxLemurProject::load() {

    xml.load("ofLemurInterface.jzml");

}


void ofxLemurProject::save() {
    
    if(!xml.tagExists("JZML")) xml.addTag("JZML");
    xml.pushTag("JZML");
    
    for(int i=0; i<interfaces.size();i++) {
        
        if(!xml.tagExists("WINDOW")) xml.addTag("WINDOW");
        xml.pushTag("WINDOW");
        
        xml.addAttribute("WINDOW", "class", "JAZZINTERFACE", i);
        xml.addAttribute("WINDOW", "text", interfaces[i]->name, i);
        xml.addAttribute("WINDOW", "x", "0", i);
        xml.addAttribute("WINDOW", "y", "0", i);
        xml.addAttribute("WINDOW", "width", "1024", i);
        xml.addAttribute("WINDOW", "height", "724", i);
        xml.addAttribute("WINDOW", "state", "1", i);
        xml.addAttribute("WINDOW", "group", "0", i);
        xml.addAttribute("WINDOW", "font", "tahoma,11,0", i);
        
        
        for(int o=0; o<interfaces[i]->objects.size();o++) {
            
            /*if(!xml.tagExists("WINDOW")) xml.addTag("WINDOW");
            xml.pushTag("WINDOW");
            xml.popTag();*/
            
            interfaces[i]->objects[o]->saveXml(&xml, i);
            
            
        }
        
        
        xml.popTag();
        
        
        
        //<WINDOW class="JAZZINTERFACE" text="Default" x="0" y="0" width="1024" height="724" state="1" group="0" font="tahoma,11,0" >
        
        
    }
    
    xml.popTag();
    xml.save("ofLemurInterface.jzml");
    
}