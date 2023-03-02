# SoftwareArchitectureCLassApplication
This is sandbox code to show proof of concept usages of some principles taught in University of Cincinnati's Software Architecture Class.

This code base will be used for several assignments, but it's value comes from having several libraries in play, as well as some example usages of concepts of singletons, static initializers, journaling, and automation APIs

Additionally, this also shows how to setup a Basic Action to verify a merge request compiles or not.


This software to show off some workflows with using Java and automation APIs depends upon a Java Provider to present.  Otherwise a build error will occur.

To Resovle this install a Java JDK (such as Adopt OpenJDK), and then provide the proper header includes and library location.  It is being proposed as future enhancment to make the jvm library be loaded dyanmically.

Or optionally comment out the code in PerformJavaAutomationWorkflow, and turn off building the JavaLoader library.

[Journaling Module Design](documentation_markdown/journaling.md)
