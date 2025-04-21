package com.example.matrixcalculator

import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.TableLayout
import android.widget.TableRow
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.example.matrixcalculator.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private external fun addMatrices(rows1: Int, cols1: Int, rows2: Int, cols2: Int, matrix1: DoubleArray, matrix2: DoubleArray): DoubleArray
    private external fun subtractMatrices(rows1: Int, cols1: Int, rows2: Int, cols2: Int, matrix1: DoubleArray, matrix2: DoubleArray): DoubleArray
    private external fun multiplyMatrices(rows1: Int, cols1: Int, rows2: Int, cols2: Int, matrix1: DoubleArray, matrix2: DoubleArray): DoubleArray
    private external fun divideMatrices(rows1: Int, cols1: Int, rows2: Int, cols2: Int, matrix1: DoubleArray, matrix2: DoubleArray): DoubleArray

    private var rows1 = 0
    private var cols1 = 0
    private var rows2 = 0
    private var cols2 = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val rows1Input = findViewById<EditText>(R.id.rows1Input)
        val cols1Input = findViewById<EditText>(R.id.cols1Input)
        val rows2Input = findViewById<EditText>(R.id.rows2Input)
        val cols2Input = findViewById<EditText>(R.id.cols2Input)
        val matrix1Table = findViewById<TableLayout>(R.id.matrix1Table)
        val matrix2Table = findViewById<TableLayout>(R.id.matrix2Table)
        val resultTable = findViewById<TableLayout>(R.id.resultTable)
        val addButton = findViewById<Button>(R.id.addButton)
        val subtractButton = findViewById<Button>(R.id.subtractButton)
        val multiplyButton = findViewById<Button>(R.id.multiplyButton)
        val divideButton = findViewById<Button>(R.id.divideButton)
        val setDim1Button = findViewById<Button>(R.id.setDim1Button)
        val setDim2Button = findViewById<Button>(R.id.setDim2Button)
        val clearButton = findViewById<Button>(R.id.clearButton)

        fun updateTable(table: TableLayout, rows: Int, cols: Int) {
            if (rows > 0 && cols > 0) {
                table.removeAllViews()
                for (i in 0 until rows) {
                    val row = TableRow(this)
                    for (j in 0 until cols) {
                        val editText = EditText(this)
                        editText.layoutParams = TableRow.LayoutParams(0, TableRow.LayoutParams.WRAP_CONTENT, 1f)
                        editText.hint = "0.0"
                        editText.inputType = android.text.InputType.TYPE_CLASS_NUMBER or android.text.InputType.TYPE_NUMBER_FLAG_DECIMAL
                        row.addView(editText)
                    }
                    table.addView(row)
                }
            }
        }

        setDim1Button.setOnClickListener {
            rows1 = rows1Input.text.toString().toIntOrNull() ?: 0
            cols1 = cols1Input.text.toString().toIntOrNull() ?: 0
            if (rows1 > 0 && cols1 > 0) {
                updateTable(matrix1Table, rows1, cols1)
            }
        }

        setDim2Button.setOnClickListener {
            rows2 = rows2Input.text.toString().toIntOrNull() ?: 0
            cols2 = cols2Input.text.toString().toIntOrNull() ?: 0
            if (rows2 > 0 && cols2 > 0) {
                updateTable(matrix2Table, rows2, cols2)
            }
        }

        addButton.setOnClickListener {
            if (rows1 != rows2 || cols1 != cols2) {
                Toast.makeText(this, "Dimensions of matrices do not match", Toast.LENGTH_SHORT).show()
                resultTable.removeAllViews()
                return@setOnClickListener
            }
            val matrix1 = getMatrixFromTable(matrix1Table, rows1, cols1)
            val matrix2 = getMatrixFromTable(matrix2Table, rows2, cols2)
            val result = addMatrices(rows1, cols1, rows2, cols2, matrix1, matrix2)
            if (result != null) {
                displayResultInTable(resultTable, rows1, cols1, result)
                Toast.makeText(this, "Output has been generated", Toast.LENGTH_SHORT).show()
            } else {
                resultTable.removeAllViews()
                resultTable.addView(TextView(this).apply { text = "Operation failed" })
            }
        }

        subtractButton.setOnClickListener {
            if (rows1 != rows2 || cols1 != cols2) {
                Toast.makeText(this, "Dimensions of matrices do not match", Toast.LENGTH_SHORT).show()
                resultTable.removeAllViews()
                return@setOnClickListener
            }
            val matrix1 = getMatrixFromTable(matrix1Table, rows1, cols1)
            val matrix2 = getMatrixFromTable(matrix2Table, rows2, cols2)
            val result = subtractMatrices(rows1, cols1, rows2, cols2, matrix1, matrix2)
            if (result != null) {
                displayResultInTable(resultTable, rows1, cols1, result)
                Toast.makeText(this, "Output has been generated", Toast.LENGTH_SHORT).show()
            } else {
                resultTable.removeAllViews()
                resultTable.addView(TextView(this).apply { text = "Operation failed" })
            }
        }

        multiplyButton.setOnClickListener {
            if (cols1 != rows2) {
                Toast.makeText(this, "Columns of Matrix 1 must equal rows of Matrix 2", Toast.LENGTH_SHORT).show()
                resultTable.removeAllViews()
                return@setOnClickListener
            }
            val matrix1 = getMatrixFromTable(matrix1Table, rows1, cols1)
            val matrix2 = getMatrixFromTable(matrix2Table, rows2, cols2)
            val result = multiplyMatrices(rows1, cols1, rows2, cols2, matrix1, matrix2)
            if (result != null) {
                displayResultInTable(resultTable, rows1, cols2, result)
                Toast.makeText(this, "Output has been generated", Toast.LENGTH_SHORT).show()
            } else {
                resultTable.removeAllViews()
                resultTable.addView(TextView(this).apply { text = "Operation failed" })
            }
        }

        divideButton.setOnClickListener {
            if (cols1 != rows2) {
                Toast.makeText(this, "Columns of Matrix 1 must equal rows of Matrix 2", Toast.LENGTH_SHORT).show()
                resultTable.removeAllViews()
                return@setOnClickListener
            }
            if (rows2 != cols2) {
                Toast.makeText(this, "Matrix 2 must be square", Toast.LENGTH_SHORT).show()
                resultTable.removeAllViews()
                return@setOnClickListener
            }
            val matrix1 = getMatrixFromTable(matrix1Table, rows1, cols1)
            val matrix2 = getMatrixFromTable(matrix2Table, rows2, cols2)
            val result = divideMatrices(rows1, cols1, rows2, cols2, matrix1, matrix2)
            if (result != null) {
                displayResultInTable(resultTable, rows1, cols2, result)
                Toast.makeText(this, "Output has been generated", Toast.LENGTH_SHORT).show()
            } else {
                resultTable.removeAllViews()
                resultTable.addView(TextView(this).apply { text = "Division not possible (determinant = 0)" })
            }
        }

        clearButton.setOnClickListener {
            rows1Input.text.clear()
            cols1Input.text.clear()
            rows2Input.text.clear()
            cols2Input.text.clear()
            matrix1Table.removeAllViews()
            matrix2Table.removeAllViews()
            resultTable.removeAllViews()
            rows1 = 0
            cols1 = 0
            rows2 = 0
            cols2 = 0
            Toast.makeText(this, "All fields cleared", Toast.LENGTH_SHORT).show()
        }
    }

    private fun getMatrixFromTable(table: TableLayout, rows: Int, cols: Int): DoubleArray {
        val matrix = DoubleArray(rows * cols)
        for (i in 0 until rows) {
            val row = table.getChildAt(i) as TableRow
            for (j in 0 until cols) {
                val editText = row.getChildAt(j) as EditText
                matrix[i * cols + j] = editText.text.toString().toDoubleOrNull() ?: 0.0
            }
        }
        return matrix
    }

    private fun displayResultInTable(table: TableLayout, rows: Int, cols: Int, result: DoubleArray) {
        table.removeAllViews()
        for (i in 0 until rows) {
            val row = TableRow(this)
            for (j in 0 until cols) {
                val textView = TextView(this)
                textView.layoutParams = TableRow.LayoutParams(0, TableRow.LayoutParams.WRAP_CONTENT, 1f)
                textView.text = String.format("%.2f", result[i * cols + j])
                row.addView(textView)
            }
            table.addView(row)
        }
    }

    companion object {
        init {
            System.loadLibrary("matrixcalculator")
        }
    }
}