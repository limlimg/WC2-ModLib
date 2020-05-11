/*
www.sourceforge.net/projects/tinyxml
Original code by Lee Thomason (www.grinninglizard.com)

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any
damages arising from the use of this software.

Permission is granted to anyone to use this software for any
purpose, including commercial applications, and to alter it and
redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must
not claim that you wrote the original software. If you use this
software in a product, an acknowledgment in the product documentation
would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and
must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source
distribution.
*/

#ifndef TINYXML_INCLUDED
#define TINYXML_INCLUDED

#include <stdio.h>
#include "cxx.h"

/*	The support for explicit isn't that universal, and it isn't really
	required - it is used to check that the TiXmlString class isn't incorrectly
	used. Be nice to old compilers and macro it here:
*/
// GCC version 3 and higher.s
#define TIXML_EXPLICIT explicit

/*
   TiXmlString is an emulation of a subset of the std::string template.
   Its purpose is to allow compiling TinyXML on compilers with no or poor STL support.
   Only the member functions relevant to the TinyXML project have been implemented.
   The buffer allocation is made by a simplistic power of 2 like mechanism : if we increase
   a string and there's no more room, we allocate a buffer twice as big as we need.
*/
struct TiXmlString {
    struct Rep {
        size_t size, capacity;
        char str[1];
    } *rep_;
#ifdef __cplusplus

    TiXmlString &operator=(const char *copy);

    // += operator. Maps to append
    TiXmlString &operator+=(const char *suffix);

    // += operator. Maps to append
    TiXmlString &operator+=(char single);

    // += operator. Maps to append
    TiXmlString &operator+=(const TiXmlString &suffix);

    // find a char in a string. Return TiXmlString::npos if not found
    size_t find(char lookup) const;

    /*	Function to reserve a big amount of data when we know we'll need it. Be aware that this
        function DOES NOT clear the content of the TiXmlString if any exists.
    */
    void reserve(size_t cap);

    TiXmlString &assign(const char *str, size_t len);

    TiXmlString &append(const char *str, size_t len);

    void quit();

#endif
};

__BEGIN_DECLS
void _ZN11TiXmlStringC1EPKc(struct TiXmlString *self, const char *copy);

void _ZN11TiXmlStringC2EPKc(struct TiXmlString *self, const char *copy);

__END_DECLS

#ifdef __cplusplus

TiXmlString operator+(const TiXmlString &a, const TiXmlString &b);

TiXmlString operator+(const TiXmlString &a, const char *b);

TiXmlString operator+(const char *a, const TiXmlString &b);

#endif

#define TIXML_STRING        struct TiXmlString

// Deprecated library function hell. Compilers want to use the
// new safe versions. This probably doesn't fully address the problem,
// but it gets closer. There are too many compilers for me to fully
// test. If you get compilation troubles, undefine TIXML_SAFE
// GCC version 3 and higher.s
//#warning( "Using sn* functions." )
#define TIXML_SNPRINTF snprintf
#define TIXML_SSCANF   sscanf

struct TiXmlBase;
struct TiXmlNode;
struct TiXmlDocument;
struct TiXmlElement;
struct TiXmlComment;
struct TiXmlUnknown;
struct TiXmlAttribute;
struct TiXmlText;
struct TiXmlDeclaration;
struct TiXmlParsingData;

const int TIXML_MAJOR_VERSION = 2;
const int TIXML_MINOR_VERSION = 6;
const int TIXML_PATCH_VERSION = 2;

/*	Internal structure for tracking location of items 
	in the XML file.
*/
struct TiXmlCursor {
    int row;    // 0 based.
    int col;    // 0 based.
};

// Only used by Attribute::Query functions
enum {
    TIXML_SUCCESS,
    TIXML_NO_ATTRIBUTE,
    TIXML_WRONG_TYPE
};

// Used by the parsing routines.
enum TiXmlEncoding {
    TIXML_ENCODING_UNKNOWN,
    TIXML_ENCODING_UTF8,
    TIXML_ENCODING_LEGACY
};

const enum TiXmlEncoding TIXML_DEFAULT_ENCODING = TIXML_ENCODING_UNKNOWN;

/** TiXmlBase is a base class for every class in TinyXml.
	It does little except to establish that TinyXml classes
	can be printed and provide some utility functions.

	In XML, the document and elements can contain
	other elements and other types of nodes.

	@verbatim
	A Document can contain:	Element	(container or leaf)
							Comment (leaf)
							Unknown (leaf)
							Declaration( leaf )

	An Element can contain:	Element (container or leaf)
							Text	(leaf)
							Attributes (not on tree)
							Comment (leaf)
							Unknown (leaf)

	A Decleration contains: Attributes (not on tree)
	@endverbatim
*/
struct _ZTV9TiXmlBase {
    void (*D1)(struct TiXmlBase *self);

    void (*D0)(struct TiXmlBase *self);

    void (*Print)(struct TiXmlBase *self, FILE *cfile, int depth);

    const char *(*Parse)(struct TiXmlBase *self, const char *p, struct TiXmlParsingData *data,
                         enum TiXmlEncoding encoding /*= TIXML_ENCODING_UNKNOWN */ );

    void (*StreamOut)(struct TiXmlBase *self, void *out);

    const struct TiXmlDocument *(*ToDocument_const)(
            const struct TiXmlNode *self); ///< Cast to a more defined type. Will return null if not of the requested type.
    const struct TiXmlElement *(*ToElement_const)(
            const struct TiXmlNode *self); ///< Cast to a more defined type. Will return null if not of the requested type.
    const struct TiXmlComment *(*ToComment_const)(
            const struct TiXmlNode *self); ///< Cast to a more defined type. Will return null if not of the requested type.
    const struct TiXmlUnknown *(*ToUnknown_const)(
            const struct TiXmlNode *self); ///< Cast to a more defined type. Will return null if not of the requested type.
    const struct TiXmlText *(*ToText_const)(
            const struct TiXmlNode *self); ///< Cast to a more defined type. Will return null if not of the requested type.
    const struct TiXmlDeclaration *(*ToDeclaration_const)(
            const struct TiXmlNode *self); ///< Cast to a more defined type. Will return null if not of the requested type.

    struct TiXmlDocument *(*ToDocument)(
            struct TiXmlNode *self); ///< Cast to a more defined type. Will return null if not of the requested type.
    struct TiXmlElement *(*ToElement)(
            struct TiXmlNode *self); ///< Cast to a more defined type. Will return null if not of the requested type.
    struct TiXmlComment *(*ToComment)(
            struct TiXmlNode *self); ///< Cast to a more defined type. Will return null if not of the requested type.
    struct TiXmlUnknown *(*ToUnknown)(
            struct TiXmlNode *self); ///< Cast to a more defined type. Will return null if not of the requested type.
    struct TiXmlText *(*ToText)(
            struct TiXmlNode *self); ///< Cast to a more defined type. Will return null if not of the requested type.
    struct TiXmlDeclaration *(*ToDeclaration)(
            struct TiXmlNode *self); ///< Cast to a more defined type. Will return null if not of the requested type.

    struct TiXmlNode *(*Clone)(struct TiXmlNode *self);
};

#define struct_TiXmlBase \
    struct _ZTV9TiXmlBase *vtable_TiXmlBase;\
    struct TiXmlCursor location;\
    void *userData;

struct TiXmlBase {
    struct_TiXmlBase
#define __base_TiXmlBase struct_TiXmlBase
#ifdef __cplusplus

    static const char *SkipWhiteSpace(const char *, TiXmlEncoding encoding);

    static bool IsWhiteSpace(char c);

    /*	Reads an XML name into the string provided. Returns
        a pointer just past the last character of the name,
        or 0 if the function has an error.
    */
    static const char *ReadName(const char *p, TIXML_STRING *name, TiXmlEncoding encoding);

    /*	Reads text. Returns a pointer past the given end tag.
        Wickedly complex options, but it keeps the (sensitive) code in one place.
    */
    static const char *ReadText(const char *in,                // where to start
                                TIXML_STRING *text,            // the string read
                                bool ignoreWhiteSpace,        // whether to keep the white space
                                const char *endTag,            // what ends this text
                                bool ignoreCase,            // whether to ignore case in the end tag
                                TiXmlEncoding encoding);    // the current encoding

    // If an entity has been found, transform it into a character.
    static const char *GetEntity(const char *in, char *value, int *length, TiXmlEncoding encoding);

    // Get a character, while interpreting entities.
    // The length can be from 0 to 4 bytes.
    static const char *GetChar(const char *p, char *_value, int *length, TiXmlEncoding encoding);

    // Return true if the next characters in the stream are any of the endTag sequences.
    // Ignore case only works for english, and should only be relied on when comparing
    // to English words: StringEqual( p, "version", true ) is fine.
    static bool
    StringEqual(const char *p, const char *endTag, bool ignoreCase, TiXmlEncoding encoding);

    // None of these methods are reliable for any language except English.
    // Good for approximation, not great for accuracy.
    static int IsAlpha(unsigned char anyByte, TiXmlEncoding encoding);

    static int IsAlphaNum(unsigned char anyByte, TiXmlEncoding encoding);

    static void ConvertUTF32ToUTF8(unsigned long input, char *output, int *length);

#endif
};

/** The types of XML nodes supported by TinyXml. (All the
        unsupported types are picked up by UNKNOWN.)
*/
enum NodeType {
    TINYXML_DOCUMENT,
    TINYXML_ELEMENT,
    TINYXML_COMMENT,
    TINYXML_UNKNOWN,
    TINYXML_TEXT,
    TINYXML_DECLARATION,
    TINYXML_TYPECOUNT
};

/** The parent class for everything in the Document Object Model.
	(Except for attributes).
	Nodes have siblings, a parent, and children. A node can be
	in a document, or stand on its own. The type of a TiXmlNode
	can be queried, and it can be cast to its more defined type.
*/
#define struct_TiXmlNode \
    struct TiXmlNode *parent;\
    enum NodeType type;\
    struct TiXmlNode *firstChild;\
    struct TiXmlNode *lastChild;\
    TIXML_STRING value;\
    struct TiXmlNode *prev;\
    struct TiXmlNode *next;

__sub_struct(TiXmlNode, TiXmlBase)
    struct_TiXmlNode
#define __base_TiXmlNode __base_TiXmlBase struct_TiXmlNode
#ifdef __cplusplus

    /// Delete all the children of this node. Does not affect 'this'.
    void Clear();

    const TiXmlNode *FirstChild(
            const char *value) const;            ///< The first child of this node with the matching 'value'. Will be null if none found.
    /// The first child of this node with the matching 'value'. Will be null if none found.
    TiXmlNode *FirstChild(const char *_value);

    const TiXmlNode *LastChild(
            const char *value) const;            /// The last child of this node matching 'value'. Will be null if there are no children.
    TiXmlNode *LastChild(const char *_value);

    /** An alternate way to walk the children of a node.
        One way to iterate over nodes is:
        @verbatim
            for( child = parent->FirstChild(); child; child = child->NextSibling() )
        @endverbatim

        IterateChildren does the same thing with the syntax:
        @verbatim
            child = 0;
            while( child = parent->IterateChildren( child ) )
        @endverbatim

        IterateChildren takes the previous child as input and finds
        the next one. If the previous child is null, it returns the
        first. IterateChildren will return null when done.
    */
    const TiXmlNode *IterateChildren(const TiXmlNode *previous) const;

    TiXmlNode *IterateChildren(const TiXmlNode *previous);

    /// This flavor of IterateChildren searches for children with a particular 'value'
    const TiXmlNode *IterateChildren(const char *value, const TiXmlNode *previous) const;

    TiXmlNode *IterateChildren(const char *_value, const TiXmlNode *previous);

    /** Add a new node related to this. Adds a child past the LastChild.
        Returns a pointer to the new object or NULL if an error occured.
    */
    TiXmlNode *InsertEndChild(const TiXmlNode &addThis);

    /** Add a new node related to this. Adds a child past the LastChild.

        NOTE: the node to be added is passed by pointer, and will be
        henceforth owned (and deleted) by tinyXml. This method is efficient
        and avoids an extra copy, but should be used with care as it
        uses a different memory model than the other insert functions.

        @sa InsertEndChild
    */
    TiXmlNode *LinkEndChild(TiXmlNode *addThis);

    /** Add a new node related to this. Adds a child before the specified child.
        Returns a pointer to the new object or NULL if an error occured.
    */
    TiXmlNode *InsertBeforeChild(TiXmlNode *beforeThis, const TiXmlNode &addThis);

    /** Add a new node related to this. Adds a child after the specified child.
        Returns a pointer to the new object or NULL if an error occured.
    */
    TiXmlNode *InsertAfterChild(TiXmlNode *afterThis, const TiXmlNode &addThis);

    /** Replace a child of this node.
        Returns a pointer to the new object or NULL if an error occured.
    */
    TiXmlNode *ReplaceChild(TiXmlNode *replaceThis, const TiXmlNode &withThis);

    /// Delete a child of this node.
    bool RemoveChild(TiXmlNode *removeThis);

    /// Navigate to a sibling node.
    const TiXmlNode *PreviousSibling(const char *) const;

    TiXmlNode *PreviousSibling(const char *_prev);

    /// Navigate to a sibling node with the given 'value'.
    const TiXmlNode *NextSibling(const char *) const;

    TiXmlNode *NextSibling(const char *_next);

    /** Convenience function to get through elements.
        Calls NextSibling and ToElement. Will skip all non-Element
        nodes. Returns 0 if there is not another element.
    */
    const TiXmlElement *NextSiblingElement() const;

    TiXmlElement *NextSiblingElement();

    /** Convenience function to get through elements.
        Calls NextSibling and ToElement. Will skip all non-Element
        nodes. Returns 0 if there is not another element.
    */
    const TiXmlElement *NextSiblingElement(const char *) const;

    TiXmlElement *NextSiblingElement(const char *_next);

    /// Convenience function to get through elements.
    const TiXmlElement *FirstChildElement() const;

    TiXmlElement *FirstChildElement();

    /// Convenience function to get through elements.
    const TiXmlElement *FirstChildElement(const char *_value) const;

    TiXmlElement *FirstChildElement(const char *_value);

    /** Return a pointer to the Document this node lives in.
        Returns null if not in a document.
    */
    const TiXmlDocument *GetDocument() const;

    TiXmlDocument *GetDocument();

    const TiXmlDocument *
    ToDocument() const; ///< Cast to a more defined type. Will return null if not of the requested type.
    const TiXmlElement *
    ToElement() const; ///< Cast to a more defined type. Will return null if not of the requested type.
    const TiXmlComment *
    ToComment() const; ///< Cast to a more defined type. Will return null if not of the requested type.
    const TiXmlUnknown *
    ToUnknown() const; ///< Cast to a more defined type. Will return null if not of the requested type.
    const TiXmlText *
    ToText() const; ///< Cast to a more defined type. Will return null if not of the requested type.
    const TiXmlDeclaration *
    ToDeclaration() const; ///< Cast to a more defined type. Will return null if not of the requested type.

    TiXmlDocument *
    ToDocument(); ///< Cast to a more defined type. Will return null if not of the requested type.
    TiXmlElement *
    ToElement(); ///< Cast to a more defined type. Will return null if not of the requested type.
    TiXmlComment *
    ToComment(); ///< Cast to a more defined type. Will return null if not of the requested type.
    TiXmlUnknown *
    ToUnknown(); ///< Cast to a more defined type. Will return null if not of the requested type.
    TiXmlText *
    ToText(); ///< Cast to a more defined type. Will return null if not of the requested type.
    TiXmlDeclaration *
    ToDeclaration(); ///< Cast to a more defined type. Will return null if not of the requested type.

    // Copy to the allocated object. Shared functionality between Clone, Copy constructor,
    // and the assignment operator.
    void CopyTo(TiXmlNode *target) const;

    // Figure out what is at *p, and parse it. Returns null if it is not an xml node.
    TiXmlNode *Identify(const char *start, TiXmlEncoding encoding);

#endif
__end_struct

__BEGIN_DECLS
void _ZN9TiXmlNodeC1ENS_8NodeTypeE(struct TiXmlNode *self, enum NodeType _type);

void _ZN9TiXmlNodeC2ENS_8NodeTypeE(struct TiXmlNode *self, enum NodeType _type);

void _ZN9TiXmlNodeD0Ev(struct TiXmlNode *self);

void _ZN9TiXmlNodeD1Ev(struct TiXmlNode *self);

void _ZN9TiXmlNodeD2Ev(struct TiXmlNode *self);

__END_DECLS

/** An attribute is a name-value pair. Elements have an arbitrary
	number of attributes, each with a unique name.

	@note The attributes are not TiXmlNodes, since they are not
		  part of the tinyXML document object model. There are other
		  suggested ways to look at this problem.
*/
__sub_struct(TiXmlAttribute, TiXmlBase)
    struct TiXmlDocument *document;    // A pointer back to a document, for error reporting.
    TIXML_STRING name;
    TIXML_STRING value;
    struct TiXmlAttribute *prev;
    struct TiXmlAttribute *next;
#ifdef __cplusplus

    /** QueryIntValue examines the value string. It is an alternative to the
        IntValue() method with richer error checking.
        If the value is an integer, it is stored in 'value' and
        the call returns TIXML_SUCCESS. If it is not
        an integer, it returns TIXML_WRONG_TYPE.

        A specialized but useful call. Note that for success it returns 0,
        which is the opposite of almost all other TinyXml calls.
    */
    int QueryIntValue(int *_value) const;

    /// QueryDoubleValue examines the value string. See QueryIntValue().
    int QueryDoubleValue(double *_value) const;

    void SetIntValue(
            int _value);                                        ///< Set the value from an integer.
    void
    SetDoubleValue(double _value);                                ///< Set the value from a double.

    /// Get the next sibling attribute in the DOM. Returns null at end.
    const TiXmlAttribute *Next() const;

    TiXmlAttribute *Next();

    /// Get the previous sibling attribute in the DOM. Returns null at beginning.
    const TiXmlAttribute *Previous() const;

    TiXmlAttribute *Previous();

    /*	Attribute parsing starts: first letter of the name
                         returns: the next char after the value end quote
    */
    const char *Parse(const char *p, TiXmlParsingData *data, TiXmlEncoding encoding);

    // Prints this Attribute to a FILE stream.
    void Print(FILE *cfile, int depth) const;

    void Print(FILE *cfile, int depth, TIXML_STRING *str) const;

#endif
__end_struct

__BEGIN_DECLS
void _ZN14TiXmlAttributeD0Ev(struct TiXmlAttribute *self);

void _ZN14TiXmlAttributeD1Ev(struct TiXmlAttribute *self);

void _ZN14TiXmlAttributeD2Ev(struct TiXmlAttribute *self);

__END_DECLS

/*	A class used to manage a group of attributes.
	It is only used internally, both by the ELEMENT and the DECLARATION.
	
	The set can be changed transparent to the Element and Declaration
	classes that use it, but NOT transparent to the Attribute
	which has to implement a next() and previous() method. Which makes
	it a bit problematic and prevents the use of STL.

	This version is implemented with circular lists because:
		- I like circular lists
		- it demonstrates some independence from the (typical) doubly linked list.
*/
struct TiXmlAttributeSet {
    struct TiXmlAttribute sentinel;
#ifdef __cplusplus

    void Add(TiXmlAttribute *attribute);

    void Remove(TiXmlAttribute *attribute);

    TiXmlAttribute *Find(const char *_name) const;

#endif
};

__BEGIN_DECLS
void _ZN17TiXmlAttributeSetC1Ev(struct TiXmlAttributeSet *self);

void _ZN17TiXmlAttributeSetC2Ev(struct TiXmlAttributeSet *self);

void _ZN17TiXmlAttributeSetD0Ev(struct TiXmlAttributeSet *self);

void _ZN17TiXmlAttributeSetD1Ev(struct TiXmlAttributeSet *self);

void _ZN17TiXmlAttributeSetD2Ev(struct TiXmlAttributeSet *self);

__END_DECLS

/** The element is a container class. It has a value, the element name,
	and can contain other elements, text, comments, and unknowns.
	Elements also contain an arbitrary number of attributes.
*/
__sub_struct(TiXmlElement, TiXmlNode)
    struct TiXmlAttributeSet attributeSet;
#ifdef __cplusplus

    TiXmlElement &operator=(const TiXmlElement &base);

    /** Given an attribute name, Attribute() returns the value
        for the attribute of that name, or null if none exists.
    */
    const char *Attribute(const char *name) const;

    /** Given an attribute name, Attribute() returns the value
        for the attribute of that name, or null if none exists.
        If the attribute exists and can be converted to an integer,
        the integer value will be put in the return 'i', if 'i'
        is non-null.
    */
    const char *Attribute(const char *name, int *i) const;

    /** Given an attribute name, Attribute() returns the value
        for the attribute of that name, or null if none exists.
        If the attribute exists and can be converted to an double,
        the double value will be put in the return 'd', if 'd'
        is non-null.
    */
    const char *Attribute(const char *name, double *d) const;

    /** QueryIntAttribute examines the attribute - it is an alternative to the
        Attribute() method with richer error checking.
        If the attribute is an integer, it is stored in 'value' and
        the call returns TIXML_SUCCESS. If it is not
        an integer, it returns TIXML_WRONG_TYPE. If the attribute
        does not exist, then TIXML_NO_ATTRIBUTE is returned.
    */
    int QueryIntAttribute(const char *name, int *_value) const;

    /// QueryDoubleAttribute examines the attribute - see QueryIntAttribute().
    int QueryDoubleAttribute(const char *name, double *_value) const;

    /// QueryFloatAttribute examines the attribute - see QueryIntAttribute().
    int QueryFloatAttribute(const char *name, float *_value) const;

    /** Sets an attribute of name to a given value. The attribute
        will be created if it does not exist, or changed if it does.
    */
    void SetAttribute(const char *name, const char *_value);

    /** Sets an attribute of name to a given value. The attribute
        will be created if it does not exist, or changed if it does.
    */
    void SetAttribute(const char *name, int value);

    /** Sets an attribute of name to a given value. The attribute
        will be created if it does not exist, or changed if it does.
    */
    void SetDoubleAttribute(const char *name, double value);

    /** Deletes an attribute with the given name.
    */
    void RemoveAttribute(const char *name);

    /// Creates a new Element and returns it - the returned element is a copy.
    TiXmlNode *Clone() const;

    // Print the Element to a FILE stream.
    void Print(FILE *cfile, int depth) const;

    /*	Attribtue parsing starts: next char past '<'
                         returns: next char past '>'
    */
    const char *Parse(const char *p, TiXmlParsingData *data, TiXmlEncoding encoding);

    const TiXmlElement *
    ToElement() const; ///< Cast to a more defined type. Will return null not of the requested type.
    TiXmlElement *
    ToElement(); ///< Cast to a more defined type. Will return null not of the requested type.

    void CopyTo(TiXmlElement *target) const;

    void ClearThis();    // like clear, but initializes 'this' object as well

    /*	[internal use]
        Reads the "value" of the element -- another element, or text.
        This should terminate with the current end tag.
    */
    const char *ReadValue(const char *in, TiXmlParsingData *prevData, TiXmlEncoding encoding);

#endif
__end_struct

__BEGIN_DECLS
void _ZN12TiXmlElementC1EPKc(struct TiXmlElement *self, const char *in_value);

void _ZN12TiXmlElementC2EPKc(struct TiXmlElement *self, const char *in_value);

void _ZN12TiXmlElementC1ERKS_(struct TiXmlElement *self, const struct TiXmlElement *);

void _ZN12TiXmlElementC2ERKS_(struct TiXmlElement *self, const struct TiXmlElement *);

void _ZN12TiXmlElementD0Ev(struct TiXmlElement *self);

void _ZN12TiXmlElementD1Ev(struct TiXmlElement *self);

void _ZN12TiXmlElementD2Ev(struct TiXmlElement *self);

__END_DECLS

/**	An XML comment.
*/
__sub_struct(TiXmlComment, TiXmlNode)
#ifdef __cplusplus

    TiXmlComment &operator=(const TiXmlComment &base);

    /// Returns a copy of this Comment.
    TiXmlNode *Clone() const;

    // Write this Comment to a FILE stream.
    void Print(FILE *cfile, int depth) const;

    /*	Attribtue parsing starts: at the ! of the !--
                         returns: next char past '>'
    */
    const char *Parse(const char *p, TiXmlParsingData *data, TiXmlEncoding encoding);

    const TiXmlComment *
    ToComment() const; ///< Cast to a more defined type. Will return null not of the requested type.
    TiXmlComment *
    ToComment(); ///< Cast to a more defined type. Will return null not of the requested type.

    void CopyTo(TiXmlComment *target) const;

#endif
__end_struct

__BEGIN_DECLS
void _ZN12TiXmlCommentC1ERKS_(struct TiXmlComment *self, const struct TiXmlComment *);

void _ZN12TiXmlCommentC2ERKS_(struct TiXmlComment *self, const struct TiXmlComment *);

void _ZN12TiXmlCommentD0Ev(struct TiXmlComment *self);

void _ZN12TiXmlCommentD1Ev(struct TiXmlComment *self);

void _ZN12TiXmlCommentD2Ev(struct TiXmlComment *self);

__END_DECLS

/** XML text. A text node can have 2 ways to output the next. "normal" output 
	and CDATA. It will default to the mode it was parsed from the XML file and
	you generally want to leave it alone, but you can change the output mode with 
	SetCDATA() and query it with CDATA().
*/
__sub_struct(TiXmlText, TiXmlNode)
    bool cdata;            // true if this should be input and output as a CDATA style text element
#ifdef __cplusplus

    // Write this text object to a FILE stream.
    void Print(FILE *cfile, int depth) const;

    const char *Parse(const char *p, TiXmlParsingData *data, TiXmlEncoding encoding);

    const TiXmlText *
    ToText() const; ///< Cast to a more defined type. Will return null not of the requested type.
    TiXmlText *
    ToText(); ///< Cast to a more defined type. Will return null not of the requested type.

    ///  [internal use] Creates a new Element and returns it.
    TiXmlNode *Clone() const;

    void CopyTo(TiXmlText *target) const;

    bool Blank() const;    // returns true if all white space and new lines
#endif
__end_struct

__BEGIN_DECLS
void _ZN9TiXmlTextD0Ev(struct TiXmlText *self);

void _ZN9TiXmlTextD1Ev(struct TiXmlText *self);

void _ZN9TiXmlTextD2Ev(struct TiXmlText *self);

__END_DECLS

/** In correct XML the declaration is the first entry in the file.
	@verbatim
		<?xml version="1.0" standalone="yes"?>
	@endverbatim

	TinyXml will happily read or write files without a declaration,
	however. There are 3 possible attributes to the declaration:
	version, encoding, and standalone.

	Note: In this version of the code, the attributes are
	handled as special cases, not generic attributes, simply
	because there can only be at most 3 and they are always the same.
*/
__sub_struct(TiXmlDeclaration, TiXmlNode)
    TIXML_STRING version;
    TIXML_STRING encoding;
    TIXML_STRING standalone;
#ifdef __cplusplus

    TiXmlDeclaration &operator=(const TiXmlDeclaration &copy);

    /// Creates a copy of this Declaration and returns it.
    TiXmlNode *Clone() const;

    void Print(FILE *cfile, int depth) const;

    const char *Parse(const char *p, TiXmlParsingData *data, TiXmlEncoding encoding);

    const TiXmlDeclaration *
    ToDeclaration() const; ///< Cast to a more defined type. Will return null not of the requested type.
    TiXmlDeclaration *
    ToDeclaration(); ///< Cast to a more defined type. Will return null not of the requested type.

    void CopyTo(TiXmlDeclaration *target) const;

#endif
__end_struct

__BEGIN_DECLS
void _ZN16TiXmlDeclarationC1EPKcS1_S1_(struct TiXmlDeclaration *self, const char *_version,
                                       const char *_encoding, const char *_standalone);

void _ZN16TiXmlDeclarationC2EPKcS1_S1_(struct TiXmlDeclaration *self, const char *_version,
                                       const char *_encoding, const char *_standalone);

void
_ZN16TiXmlDeclarationC1ERKS_(struct TiXmlDeclaration *self, const struct TiXmlDeclaration *copy);

void
_ZN16TiXmlDeclarationC2ERKS_(struct TiXmlDeclaration *self, const struct TiXmlDeclaration *copy);

void _ZN16TiXmlDeclarationD0Ev(struct TiXmlDeclaration *self);

void _ZN16TiXmlDeclarationD1Ev(struct TiXmlDeclaration *self);

void _ZN16TiXmlDeclarationD2Ev(struct TiXmlDeclaration *self);

__END_DECLS

/** Any tag that tinyXml doesn't recognize is saved as an
	unknown. It is a tag of text, but should not be modified.
	It will be written back to the XML, unchanged, when the file
	is saved.

	DTD tags get thrown into TiXmlUnknowns.
*/
__sub_struct(TiXmlUnknown, TiXmlNode)
#ifdef __cplusplus

    /// Creates a copy of this Unknown and returns it.
    TiXmlNode *Clone() const;

    // Print this Unknown to a FILE stream.
    void Print(FILE *cfile, int depth) const;

    const char *Parse(const char *p, TiXmlParsingData *data, TiXmlEncoding encoding);

    const TiXmlUnknown *
    ToUnknown() const; ///< Cast to a more defined type. Will return null not of the requested type.
    TiXmlUnknown *
    ToUnknown(); ///< Cast to a more defined type. Will return null not of the requested type.


    void CopyTo(TiXmlUnknown *target) const;

#endif
__end_struct

__BEGIN_DECLS
void _ZN12TiXmlUnknownD0Ev(struct TiXmlUnknown *self);

void _ZN12TiXmlUnknownD1Ev(struct TiXmlUnknown *self);

void _ZN12TiXmlUnknownD2Ev(struct TiXmlUnknown *self);

__END_DECLS

/** Always the top level node. A document binds together all the
	XML pieces. It can be saved, loaded, and printed to the screen.
	The 'value' of a document node is the xml file name.
*/
__sub_struct(TiXmlDocument, TiXmlNode)
    bool error;
    int errorId;
    TIXML_STRING errorDesc;
    int tabsize;
    struct TiXmlCursor errorLocation;
    bool useMicrosoftBOM;        // the UTF-8 BOM were found when read. Note this, and try to write.
#ifdef __cplusplus

    TiXmlDocument &operator=(const TiXmlDocument &copy);

    /** Load a file using the current document value.
        Returns true if successful. Will delete any existing
        document data before loading.
    */
    bool LoadFile(TiXmlEncoding encoding = TIXML_DEFAULT_ENCODING);

    /// Save a file using the current document value. Returns true if successful.
    bool SaveFile() const;

    /// Load a file using the given filename. Returns true if successful.
    bool LoadFile(const char *filename, TiXmlEncoding encoding = TIXML_DEFAULT_ENCODING);

    /// Save a file using the given filename. Returns true if successful.
    bool SaveFile(const char *filename) const;

    /** Load a file using the given FILE*. Returns true if successful. Note that this method
        doesn't stream - the entire object pointed at by the FILE*
        will be interpreted as an XML file. TinyXML doesn't stream in XML from the current
        file location. Streaming may be added in the future.
    */
    bool LoadFile(FILE *, TiXmlEncoding encoding = TIXML_DEFAULT_ENCODING);

    /// Save a file using the given FILE*. Returns true if successful.
    bool SaveFile(FILE *) const;

    /** Parse the given null terminated block of xml data. Passing in an encoding to this
        method (either TIXML_ENCODING_LEGACY or TIXML_ENCODING_UTF8 will force TinyXml
        to use that encoding, regardless of what TinyXml might otherwise try to detect.
    */
    const char *Parse(const char *p, TiXmlParsingData *data = 0,
                      TiXmlEncoding encoding = TIXML_DEFAULT_ENCODING);

    /// Print this Document to a FILE stream.
    void Print(FILE *cfile, int depth = 0) const;

    // [internal use]
    void SetError(int err, const char *errorLocation, TiXmlParsingData *prevData,
                  TiXmlEncoding encoding);

    const TiXmlDocument *
    ToDocument() const; ///< Cast to a more defined type. Will return null not of the requested type.
    TiXmlDocument *
    ToDocument(); ///< Cast to a more defined type. Will return null not of the requested type.

    // [internal use]
    TiXmlNode *Clone() const;

    void CopyTo(TiXmlDocument *target) const;

#endif
__end_struct

__BEGIN_DECLS
void _ZN13TiXmlDocumentC1Ev(struct TiXmlDocument *self);

void _ZN13TiXmlDocumentC2Ev(struct TiXmlDocument *self);

void _ZN13TiXmlDocumentC1EPKc(struct TiXmlDocument *self, const char *documentName);

void _ZN13TiXmlDocumentC2EPKc(struct TiXmlDocument *self, const char *documentName);

void _ZN13TiXmlDocumentC1ERKS_(struct TiXmlDocument *self, const struct TiXmlDocument *copy);

void _ZN13TiXmlDocumentC2ERKS_(struct TiXmlDocument *self, const struct TiXmlDocument *copy);

void _ZN13TiXmlDocumentD0Ev(struct TiXmlDocument *self);

void _ZN13TiXmlDocumentD1Ev(struct TiXmlDocument *self);

void _ZN13TiXmlDocumentD2Ev(struct TiXmlDocument *self);

__END_DECLS

/**
	A TiXmlHandle is a class that wraps a node pointer with null checks; this is
	an incredibly useful thing. Note that TiXmlHandle is not part of the TinyXml
	DOM structure. It is a separate utility class.

	Take an example:
	@verbatim
	<Document>
		<Element attributeA = "valueA">
			<Child attributeB = "value1" />
			<Child attributeB = "value2" />
		</Element>
	<Document>
	@endverbatim

	Assuming you want the value of "attributeB" in the 2nd "Child" element, it's very 
	easy to write a *lot* of code that looks like:

	@verbatim
	TiXmlElement* root = document.FirstChildElement( "Document" );
	if ( root )
	{
		TiXmlElement* element = root->FirstChildElement( "Element" );
		if ( element )
		{
			TiXmlElement* child = element->FirstChildElement( "Child" );
			if ( child )
			{
				TiXmlElement* child2 = child->NextSiblingElement( "Child" );
				if ( child2 )
				{
					// Finally do something useful.
	@endverbatim

	And that doesn't even cover "else" cases. TiXmlHandle addresses the verbosity
	of such code. A TiXmlHandle checks for null	pointers so it is perfectly safe 
	and correct to use:

	@verbatim
	TiXmlHandle docHandle( &document );
	TiXmlElement* child2 = docHandle.FirstChild( "Document" ).FirstChild( "Element" ).Child( "Child", 1 ).ToElement();
	if ( child2 )
	{
		// do something useful
	@endverbatim

	Which is MUCH more concise and useful.

	It is also safe to copy handles - internally they are nothing more than node pointers.
	@verbatim
	TiXmlHandle handleCopy = handle;
	@endverbatim

	What they should not be used for is iteration:

	@verbatim
	int i=0; 
	while ( true )
	{
		TiXmlElement* child = docHandle.FirstChild( "Document" ).FirstChild( "Element" ).Child( "Child", i ).ToElement();
		if ( !child )
			break;
		// do something
		++i;
	}
	@endverbatim

	It seems reasonable, but it is in fact two embedded while loops. The Child method is 
	a linear walk to find the element, so this code would iterate much more than it needs 
	to. Instead, prefer:

	@verbatim
	TiXmlElement* child = docHandle.FirstChild( "Document" ).FirstChild( "Element" ).FirstChild( "Child" ).ToElement();

	for( child; child; child=child->NextSiblingElement() )
	{
		// do something
	}
	@endverbatim
*/
struct TiXmlHandle {
    struct TiXmlNode *node;
#ifdef __cplusplus

    /// Return a handle to the first child node.
    TiXmlHandle FirstChild() const;

    /// Return a handle to the first child node with the given name.
    TiXmlHandle FirstChild(const char *value) const;

    /// Return a handle to the first child element.
    TiXmlHandle FirstChildElement() const;

    /// Return a handle to the first child element with the given name.
    TiXmlHandle FirstChildElement(const char *value) const;

    /** Return a handle to the "index" child.
        The first child is 0, the second 1, etc.
    */
    TiXmlHandle Child(int index) const;

    /** Return a handle to the "index" child element with the given name.
        The first child element is 0, the second 1, etc. Note that only TiXmlElements
        are indexed: other types are not counted.
    */
    TiXmlHandle ChildElement(const char *value, int index) const;

    /** Return a handle to the "index" child element.
        The first child element is 0, the second 1, etc. Note that only TiXmlElements
        are indexed: other types are not counted.
    */
    TiXmlHandle ChildElement(int index) const;

#endif
};

#endif