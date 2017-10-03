#The places to look for the library folders
set(FIND_CELOFAN_PATHS
        C:/Users/GPA/ClionProjects/Celofan
        )

#The location of the include folder (and thus the header files)
#find_path uses the paths we defined above as places to look
#Saves the location of the header files in a variable called TINYXML2_INCLUDE_DIR
find_path(CELOFAN_INCLUDE_DIR Celofan.h   #The variable to store the path in and the name of the header files
            PATH_SUFFIXES Headers
            PATHS ${FIND_CELOFAN_PATHS})       #Where to look (defined above)

#The location of the lib folder (and thus the .a file)
#find_library uses the paths we defined above as places to look
#Saves the location of the .a file in a variable called TINYXML2_LIBRARY
find_library(CELOFAN_LIBRARY               #The variable to store where it found the .a files
        NAMES Celofan                      #The name of the .a file (without the extension and without the 'lib')
        PATH_SUFFIXES cmake-build-debug    #The folder the .a file is in
        PATHS ${FIND_CELOFAN_PATHS})       #Where to look (defined above)