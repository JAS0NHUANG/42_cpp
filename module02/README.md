# Notions:  

## Orthodox Canonical Form
https://www.francescmm.com/orthodox-canonical-class-form/  
https://wiki.c2.com/?CanonicalForm  
https://en.wikipedia.org/wiki/Jim_Coplien  

James O. Coplien, 1992, Advanced C₊₊ programming styles and idioms, Chapter 3, Section 2 (pp. 44)
[book link](https://archive.org/details/advancedcbsprogr00copl/page/44/mode/2up)

What should be included:  
- Default constructor
- Copy constructor
- Destructor
- Copy assignment operator

## Copy constructor
```
ClassName(const ClassName &theObject);
```

then inside the function, assign the "theObject" to "this"
This is dependent to the copy asignment operator. Meaning that if the copy asignment operator is not correctly overloaded, the behavior of this assignment might not be correct.  
```
*this = theObject;
```

## Copy assignment operator
operator overloading 
```
ClassName &ClassName::operation=(const ClassName &object);
```

## Fixed-point number
	[Berkeley - Intro to Fixed Point Number](https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html)  
	[Simple Fixed-Point Math](https://spin.atomicobject.com/2012/03/15/simple-fixed-point-math/)  
	(why we need to use int64_t to do multiplication / division)  


- Mantissa:  
	[ScienceDirect - Mantissa](https://www.sciencedirect.com/topics/computer-science/mantissa)  


## increment / decrement operator overloading
https://www.tutorialspoint.com/cplusplus/increment_decrement_operators_overloading.htm


## Check the side of one point relative to a line.
[Dot product](https://en.wikipedia.org/wiki/Dot_product)  
[Calculate on which side of a straight line is a given point located?](https://math.stackexchange.com/questions/274712/calculate-on-which-side-of-a-straight-line-is-a-given-point-located)  

## Initializer list
[When do we use Initializer List in C++?](https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/)  

