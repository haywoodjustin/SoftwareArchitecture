# TranslationWithBoost

A project to get students starting to run with boost translation

To regenerate the po and mo file.  You will need to get a copy of gettext-tools (this demo uses gettext-tools-static-0.18.1.1)

<path>\xgettext.exe --keyword=Localize:1,1t --keyword=Localize:1,2,3t --keyword=Localize:1,2,3t --keyword=Localize:1c,2,3,4t --keyword=Localize:2,1c,2t  translation.cpp

Make edits to po file.  Be aware you need to change header to overwrite the following lines in the default po file.
```
"Language: de \n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=UTF-8\n"
"Content-Transfer-Encoding: 8bit\n"
"Plural-Forms: nplurals=INTEGER; plural=EXPRESSION;\n"
```

<path>\msgfmt.exe --o messages.mo messages.po

move messages.mo de\LC_MESSAGES\messages.mo

  
  And the finally in LocalizationUtils.cpp
  genPtr->add_messages_path("C:\\Users\\polek\\source\\repos\\boost_starting\\translation");
  
  Fix this line to be where the mo files are located at.
