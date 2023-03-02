// JavaLoader.cpp : Defines the exported functions for the DLL.
//

#include "JavaLoader.h"

#include "..\JNI_Includes\jni.h"
#include <iostream>
#include "..\Core\CoreUtils.h"
#include "..\Core\LibraryLoad.h"
#include <fstream>

static JavaVM* javaVM = nullptr;

typedef jint(*createJVMFuncPointer_t)(JavaVM** p_vm, void** p_env, void* vm_arg);


void CreateJVM()
{
    //Get ENV
    char* jdkHomeENV;
    size_t len;
    errno_t err = _dupenv_s(&jdkHomeENV, &len, "JDK_HOME");

    if (err || jdkHomeENV == nullptr)
    {
        std::cout << "Can't create a JVM without knowing where it is at " << std::endl;
        // Can't create a JVM without knowing where it is at
        return;
    }
    std::string jvmLibPath = std::string(jdkHomeENV) + "\\bin\\server\\jvm.dll";
    // Verify location of libjvm
    bool libExists = std::ifstream(jvmLibPath).good();
    if (!libExists)
    {
        std::cout << "File does exist :  " << jvmLibPath << std::endl;
        return;
    }

    // Load library
    HINSTANCE jvmLib = CoreLoadLibrary(jvmLibPath.c_str());

    // Find symbol to create JVM
    createJVMFuncPointer_t createJVM = (createJVMFuncPointer_t)GetProcAddress(jvmLib, "JNI_CreateJavaVM");

    JNIEnv* env;       /* pointer to native method interface */
    JavaVMInitArgs vm_args; /* JDK/JRE 6 VM initialization arguments */
    JavaVMOption* options = new JavaVMOption[1];
    std::string tmp = "-Djava.class.path=" + BasePath() + "\\CustomClassLoader";
    options[0].optionString = _strdup(tmp.c_str());
    //options[0].optionString = _strdup("-Djava.class.path=C:\\Users\\polek\\source\\repos\\JNI_JVM_example\\SimpleHelloWorldJava");

    vm_args.version = JNI_VERSION_10;
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = false;

    /* load and initialize a Java VM, return a JNI interface
     * pointer in env */
    jint flag = createJVM(&javaVM, (void**)&env, &vm_args);

    if (flag == JNI_ERR)
    {
        std::cout << "Error creating VM. Exiting...n";
        throw new std::exception("Error creating VM");
    }
}


void RunJavaProgramWithOutClassLoader(std::string msg)
{
    JNIEnv* env;
    javaVM->GetEnv((void**)&env, JNI_VERSION_10);

    jclass cls = env->FindClass("HelloWorld");
    if (cls == nullptr)
    {
        throw new std::exception("Could not fined HelloWorld");
    }

    jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
    if (mid == nullptr)
    {
        throw new std::exception("Could not find HelloWorld.Main(string array)");
    }

    jobjectArray stringArray;
    jstring keyString = env->NewStringUTF(msg.c_str());
    stringArray = env->NewObjectArray(1, env->FindClass("[Ljava/lang/String;"), keyString);

    env->CallStaticVoidMethod(cls, mid, stringArray);
    jthrowable jexc = env->ExceptionOccurred();
    if (jexc != nullptr)
    {
        std::cout << "Error occured" << std::endl;
        env->ExceptionDescribe();
    }
}

void RunJavaProgramWithClassLoader(std::string msg)
{
    JNIEnv* env;
    javaVM->GetEnv((void**)&env, JNI_VERSION_10);

    jclass cls = env->FindClass("CustomClassLoader");
    if (cls == nullptr)
    {
        throw new std::exception("Could not fined CustomClassLoader");
    }

    jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
    if (mid == nullptr)
    {
        throw new std::exception("Could not fined CustomClassLoader.Main(string array)");
    }

    jobjectArray stringArray;
    jstring keyString = env->NewStringUTF(msg.c_str());
    stringArray = env->NewObjectArray(1, env->FindClass("[Ljava/lang/String;"), keyString);

    env->CallStaticVoidMethod(cls, mid, stringArray);
    jthrowable jexc = env->ExceptionOccurred();
    if (jexc != nullptr)
    {
        std::cout << "Error occured" << std::endl;
        env->ExceptionDescribe();
    }
}

void DestroyJVM()
{
    if (javaVM != nullptr)
    {
        javaVM->DestroyJavaVM();
    }
}
