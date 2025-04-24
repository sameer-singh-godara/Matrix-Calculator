
# Matrix Calculator

## Overview
This is an Android application developed in Kotlin for the "Mobile Computing" course, Assignment 3. The app performs matrix operations (addition, subtraction, multiplication, and division) on two matrices with user-defined dimensions, as per the assignment requirements. The matrix computations are implemented in C++ using the `std::vector` library and interfaced with Kotlin via JNI (Java Native Interface). This README documents the implementation details and how the assignment questions have been addressed.

## GitHub Repository
- **Link**: [https://github.com/sameer-singh-godara/Matrix-Calculator.git](https://github.com/sameer-singh-godara/Matrix-Calculator.git)
- The repository is private; please ensure access is granted to the instructor via GitHub for evaluation.

## Implementation Details

### How I Solved the Assignment

#### Question 1: Write a Matrix Calculator
The assignment required a matrix calculator that supports addition, subtraction, multiplication, and division of matrices with arbitrary dimensions, using a C++ library for vector operations and interfacing native code with Kotlin/Java. The following criteria were addressed:

- **Activity with the UI (10 marks)**:
  - Designed `activity_main.xml` with a `ScrollView` containing a `LinearLayout` for input fields (`rows1Input`, `cols1Input`, `rows2Input`, `cols2Input`), buttons (`setDim1Button`, `setDim2Button`, `addButton`, `subtractButton`, `multiplyButton`, `divideButton`, `clearButton`), and `TableLayout` views (`matrix1Table`, `matrix2Table`, `resultTable`) for matrix input and output. The UI is responsive and scrollable for larger matrices.
- **Interface to Accept Input (10 marks)**:
  - Implemented dynamic table generation in `MainActivity.kt` using the `updateTable` function, which creates `EditText` fields based on user-specified dimensions (up to 10x10). Input validation ensures non-zero dimensions and displays `Toast` messages for errors (e.g., "Please enter valid dimensions (1-10)").
- **Use of a C++ Library for Vector Operations (5 marks)**:
  - Utilized `std::vector` in `native-lib.cpp` to represent matrices as 2D vectors (`std::vector<std::vector<double>>`). All operations (addition, subtraction, multiplication, and division) are implemented using vector operations for efficient memory management and iteration.
- **Use of Native Code and Its Interfacing with Kotlin/Java (15 marks)**:
  - Developed `native-lib.cpp` with JNI functions (`addMatrices`, `subtractMatrices`, `multiplyMatrices`, `divideMatrices`) that perform matrix operations. These functions are declared in `MainActivity.kt` as `external` and linked via `System.loadLibrary("matrixcalculator")`. The C++ code receives matrix data as `jdoubleArray`, processes it, and returns results to Kotlin for display.

### Files
- **Kotlin**:
  - `MainActivity.kt`: Manages the UI, handles user inputs, validates dimensions, calls native functions, and displays results in a table.
- **C++**:
  - `native-lib.cpp`: Implements matrix operations using `std::vector` and JNI to interface with Kotlin.
  - `native-lib.h`: Declares JNI function signatures.
- **XML**:
  - `activity_main.xml`: Defines the UI layout with input fields, buttons, and table layouts for matrices.
- **CMake**:
  - `CMakeLists.txt`: Configures the build process for the native C++ library, linking `native-lib.cpp` to create `libmatrixcalculator.so`.

### Limitations
- Maximum matrix dimensions are limited to 10 rows and 10 columns to ensure performance and usability on mobile devices.

### Future Work
- Optimize C++ code using advanced libraries like Eigen for better performance.
- Enhance UI with custom styling or animations for improved user experience.
- Add unit tests for native C++ functions and Kotlin logic.

### Submission
- **Files Uploaded**: Kotlin sources (`MainActivity.kt`), C++ sources (`native-lib.cpp`, `native-lib.h`), XML layout (`activity_main.xml`), CMake configuration (`CMakeLists.txt`), and this README are committed to the GitHub repository.
- **Submission Method**: Uploaded to both the course management system (e.g., Google Classroom) and the private GitHub repository [https://github.com/sameer-singh-godara/Matrix-Calculator.git](https://github.com/sameer-singh-godara/Matrix-Calculator.git).

