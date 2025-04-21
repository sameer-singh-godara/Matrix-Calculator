#ifndef NATIVE_LIB_H
#define NATIVE_LIB_H

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

jdoubleArray Java_com_example_matrixcalculator_MainActivity_addMatrices(JNIEnv *env, jobject, jint dim, jdoubleArray matrix1, jdoubleArray matrix2);
jdoubleArray Java_com_example_matrixcalculator_MainActivity_subtractMatrices(JNIEnv *env, jobject, jint dim, jdoubleArray matrix1, jdoubleArray matrix2);
jdoubleArray Java_com_example_matrixcalculator_MainActivity_multiplyMatrices(JNIEnv *env, jobject, jint dim, jdoubleArray matrix1, jdoubleArray matrix2);
jdoubleArray Java_com_example_matrixcalculator_MainActivity_divideMatrices(JNIEnv *env, jobject, jint dim, jdoubleArray matrix1, jdoubleArray matrix2);

#ifdef __cplusplus
}
#endif

#endif