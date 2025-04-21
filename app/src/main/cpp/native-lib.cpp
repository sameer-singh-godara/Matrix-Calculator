#include <jni.h>
#include <vector>
#include <string>

extern "C" JNIEXPORT jdoubleArray JNICALL
Java_com_example_matrixcalculator_MainActivity_addMatrices(JNIEnv *env, jobject, jint rows1, jint cols1, jint rows2, jint cols2, jdoubleArray matrix1, jdoubleArray matrix2) {
    jsize len1 = env->GetArrayLength(matrix1);
    jsize len2 = env->GetArrayLength(matrix2);
    if (len1 != len2 || rows1 * cols1 != len1 || rows2 * cols2 != len2) {
        return nullptr;
    }
    if (rows1 != rows2) {
        return nullptr; // Rows must match
    }
    if (cols1 != cols2) {
        return nullptr; // Columns must match
    }
    jdouble *m1 = env->GetDoubleArrayElements(matrix1, nullptr);
    jdouble *m2 = env->GetDoubleArrayElements(matrix2, nullptr);

    std::vector<std::vector<double>> mat1(rows1, std::vector<double>(cols1));
    std::vector<std::vector<double>> mat2(rows2, std::vector<double>(cols2));
    std::vector<std::vector<double>> result(rows1, std::vector<double>(cols1));
    int k = 0;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            mat1[i][j] = m1[k];
            mat2[i][j] = m2[k];
            k++;
        }
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    jdoubleArray jResult = env->NewDoubleArray(len1);
    k = 0;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            env->SetDoubleArrayRegion(jResult, k++, 1, &result[i][j]);
        }
    }

    env->ReleaseDoubleArrayElements(matrix1, m1, 0);
    env->ReleaseDoubleArrayElements(matrix2, m2, 0);
    return jResult;
}

extern "C" JNIEXPORT jdoubleArray JNICALL
Java_com_example_matrixcalculator_MainActivity_subtractMatrices(JNIEnv *env, jobject, jint rows1, jint cols1, jint rows2, jint cols2, jdoubleArray matrix1, jdoubleArray matrix2) {
    jsize len1 = env->GetArrayLength(matrix1);
    jsize len2 = env->GetArrayLength(matrix2);
    if (len1 != len2 || rows1 * cols1 != len1 || rows2 * cols2 != len2) {
        return nullptr;
    }
    if (rows1 != rows2) {
        return nullptr; // Rows must match
    }
    if (cols1 != cols2) {
        return nullptr; // Columns must match
    }
    jdouble *m1 = env->GetDoubleArrayElements(matrix1, nullptr);
    jdouble *m2 = env->GetDoubleArrayElements(matrix2, nullptr);

    std::vector<std::vector<double>> mat1(rows1, std::vector<double>(cols1));
    std::vector<std::vector<double>> mat2(rows2, std::vector<double>(cols2));
    std::vector<std::vector<double>> result(rows1, std::vector<double>(cols1));
    int k = 0;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            mat1[i][j] = m1[k];
            mat2[i][j] = m2[k];
            k++;
        }
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }

    jdoubleArray jResult = env->NewDoubleArray(len1);
    k = 0;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            env->SetDoubleArrayRegion(jResult, k++, 1, &result[i][j]);
        }
    }

    env->ReleaseDoubleArrayElements(matrix1, m1, 0);
    env->ReleaseDoubleArrayElements(matrix2, m2, 0);
    return jResult;
}

extern "C" JNIEXPORT jdoubleArray JNICALL
Java_com_example_matrixcalculator_MainActivity_multiplyMatrices(JNIEnv *env, jobject, jint rows1, jint cols1, jint rows2, jint cols2, jdoubleArray matrix1, jdoubleArray matrix2) {
    if (cols1 != rows2) {
        return nullptr;
    }
    jsize len1 = env->GetArrayLength(matrix1);
    jsize len2 = env->GetArrayLength(matrix2);
    if (rows1 * cols1 != len1 || rows2 * cols2 != len2) {
        return nullptr;
    }
    jdouble *m1 = env->GetDoubleArrayElements(matrix1, nullptr);
    jdouble *m2 = env->GetDoubleArrayElements(matrix2, nullptr);

    std::vector<std::vector<double>> mat1(rows1, std::vector<double>(cols1));
    std::vector<std::vector<double>> mat2(rows2, std::vector<double>(cols2));
    std::vector<std::vector<double>> result(rows1, std::vector<double>(cols2));
    int k = 0;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            mat1[i][j] = m1[k++];
        }
    }
    k = 0;
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            mat2[i][j] = m2[k++];
        }
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    jdoubleArray jResult = env->NewDoubleArray(rows1 * cols2);
    k = 0;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            env->SetDoubleArrayRegion(jResult, k++, 1, &result[i][j]);
        }
    }

    env->ReleaseDoubleArrayElements(matrix1, m1, 0);
    env->ReleaseDoubleArrayElements(matrix2, m2, 0);
    return jResult;
}

extern "C" JNIEXPORT jdoubleArray JNICALL
Java_com_example_matrixcalculator_MainActivity_divideMatrices(JNIEnv *env, jobject, jint rows1, jint cols1, jint rows2, jint cols2, jdoubleArray matrix1, jdoubleArray matrix2) {
    if (cols1 != rows2) {
        return nullptr; // Columns of Matrix 1 must equal rows of Matrix 2
    }
    if (rows2 != cols2) {
        return nullptr; // Matrix 2 must be square
    }
    if (rows1 != cols1) {
        return nullptr; // Matrix 1 must be square for compatibility with result
    }
    jsize len1 = env->GetArrayLength(matrix1);
    jsize len2 = env->GetArrayLength(matrix2);
    if (rows1 * cols1 != len1 || rows2 * cols2 != len2) {
        return nullptr;
    }
    jdouble *m1 = env->GetDoubleArrayElements(matrix1, nullptr);
    jdouble *m2 = env->GetDoubleArrayElements(matrix2, nullptr);

    std::vector<std::vector<double>> mat1(rows1, std::vector<double>(cols1));
    std::vector<std::vector<double>> mat2(rows2, std::vector<double>(cols2));
    std::vector<std::vector<double>> result(rows1, std::vector<double>(cols2));
    int k = 0;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            mat1[i][j] = m1[k++];
        }
    }
    k = 0;
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            mat2[i][j] = m2[k++];
        }
    }

    // Compute inverse of mat2 (only for 2x2 matrices for now)
    std::vector<std::vector<double>> inverse(rows2, std::vector<double>(cols2));
    if (rows2 == 2 && cols2 == 2) {
        double det = mat2[0][0] * mat2[1][1] - mat2[0][1] * mat2[1][0];
        if (det == 0) return nullptr; // Non-invertible matrix
        inverse[0][0] = mat2[1][1] / det;
        inverse[0][1] = -mat2[0][1] / det;
        inverse[1][0] = -mat2[1][0] / det;
        inverse[1][1] = mat2[0][0] / det;
    } else {
        // Placeholder for larger matrices - implement full inverse algorithm here
        return nullptr; // Indicate that only 2x2 is supported for now
    }

    // Multiply mat1 by inverse of mat2
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * inverse[k][j];
            }
        }
    }

    jdoubleArray jResult = env->NewDoubleArray(rows1 * cols2);
    k = 0;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            env->SetDoubleArrayRegion(jResult, k++, 1, &result[i][j]);
        }
    }

    env->ReleaseDoubleArrayElements(matrix1, m1, 0);
    env->ReleaseDoubleArrayElements(matrix2, m2, 0);
    return jResult;
}