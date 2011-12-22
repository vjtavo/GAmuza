/*
 * Copyright (c) 2011 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxPd for documentation
 *
 */
#include "ofxPdTypes.h"
	
/// PATCH
//----------------------------------------------------------
Patch::Patch() : _handle(NULL), _dollarZero(0), _dollarZeroStr("0"),
	_filename(""), _path("") {}

Patch::Patch(void* handle, int dollarZero, const std::string& filename, const std::string& path) :
	_handle(handle), _dollarZero(dollarZero), _dollarZeroStr(""), 
	_filename(filename), _path(path) {
	_dollarZeroStr = ofToString(dollarZero);
}
	
bool Patch::isValid() const {
	if(_handle == NULL)
		return false;
	return true;
}

/// clear data
void Patch::clear() {
	_handle = NULL;
	_dollarZero = 0;
	_dollarZeroStr = "0";
	_filename = "";
	_path = "";
}

/// copy constructor
Patch::Patch(const Patch& from) {
	_handle = from._handle;
	_dollarZero = from._dollarZero;
	_dollarZeroStr = from._dollarZeroStr;
	_filename = from._filename;
	_path = from._path;
}

/// copy operator
void Patch::operator=(const Patch& from) {
	_handle = from._handle;
	_dollarZero = from._dollarZero;
	_dollarZeroStr = from._dollarZeroStr;
	_filename = from._filename;
	_path = from._path;
}

/// print to ostream
std::ostream& operator<<(std::ostream& os, const Patch& from) {
	return os << "Patch: \"" << from.filename() << "\" $0: " << from.dollarZeroStr()
	   		  << " valid: " << from.isValid();
}

/// LIST	
//----------------------------------------------------------
bool List::isFloat(const unsigned int index) const {
	if(index < objects.size())
		if(objects[index].type == List::FLOAT)
			return true;
	return false;
}

bool List::isSymbol(const unsigned int index) const {
	if(index < objects.size())
		if(objects[index].type == List::SYMBOL)
			return true;
	return false;
}

//----------------------------------------------------------
float List::asFloat(const unsigned int index) const {
	if(!isFloat(index)) {
		ofLog(OF_LOG_WARNING, "ofxPd: List: object is not a float");
		return 0;
	}
	return objects[index].value;
}

std::string List::asSymbol(const unsigned int index) const {
	if(!isSymbol(index)) {
		ofLog(OF_LOG_WARNING, "ofxPd: List: object is not a symbol");
		return "";
	}
	return objects[index].symbol;
}

//----------------------------------------------------------
void List::addFloat(const float value) {
	MsgObject o;
	o.type = List::FLOAT;
	o.value = value;
	objects.push_back(o);
	typeString += 'f';
}

void List::addSymbol(const std::string& symbol) {
	MsgObject o;
	o.type = List::SYMBOL;
	o.symbol = symbol;
	objects.push_back(o);
	typeString += 's';
}

List& List::operator<<(const bool var) {
    addFloat((float) var);
}

List& List::operator<<(const int var) {
    addFloat((float) var);
}

List& List::operator<<(const float var) {
    addFloat((float) var);
}

List& List::operator<<(const double var) {
    addFloat((float) var);
}
        
List& List::operator<<(const char var) {
    std::string s;
	s = var;
	addSymbol(s);
}

List& List::operator<<(const char* var) {
    addSymbol((std::string) var);
}

List& List::operator<<(const std::string& var) {
    addSymbol((std::string) var);
}

//----------------------------------------------------------
const unsigned int List::len() const {
	return objects.size();
}

const std::string& List::types() const {
	return typeString;
}

void List::clear() {
	typeString = "";
	objects.clear();
}

std::string List::toString() const {
	
	string line;
	
	for(int i = 0; i < objects.size(); ++i) {
		if(isFloat(i))
			line += ofToString(asFloat(i));
		else
			line += asSymbol(i);
		line += " ";
	}
	
	return line;
}

std::ostream& operator<<(std::ostream& os, const List& from) {
	return os << from.toString();
}
		