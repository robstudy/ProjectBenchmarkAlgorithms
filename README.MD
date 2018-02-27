<h1>Project 1: Benchmark of Algorithms</h1>

<b>Learning outcomes:</b>
- Implementation of key sorting algorithms.
- C++ programming with the appropriate use of object oriented programming and design patterns (prototype).
- Team work (if not individual project)
- Writing skills: to write a well-structured, well written and illustrated technical report.
- Critical thinking: to match the theoretical complexity of the algorithms and the observations acquired during the implementation

<b>Goals of the project:</b>
- You have to evaluate the time that it takes to do a basic sort in an array by considering:
	* Different sizes:
		* n = 10, 1000, 10000, 100000, 1000000.
	* Different types of array:
		* The array is already sorted
		* The array is completely shuffled (random values)
		* The array is sorted in the reverse order
		* The array is sorted and shuffled at 10%
	* Different sorting algorithms
		* Insertion sort
		* Selection sort
		* Bubble sort
		* Quick sort
		* Merge sort
- You have to run 100 times each condition and report the means and standard deviation in a report, by presenting figures and tables in a report
- You have to consider the statistical analysis given during the class to draw conclusions and discuss the results based on the theoretical analysis given in the class. If you don't use the technique seen in class (you don't need to implement them, you can research tools that can give you the results), you need to give a meaningful interpretation of the obtained means and standard deviations that you obtain.
- If the duration to run a function is more than X hours, depending on how long you can afford to run an algorithm. You can just mention the upper limit that you fix yourself in the evaluation. There is no penalty if some values are missing and you can justify why.

<b>Marking scheme
Code(70%)</b>
	<ol>
		<li>The project is submitted with a readme file that explains what it contains, who has done the project, and it tells how to use the files.</li>
		<li>The project compiles.</li>
		<li>The project is commented (e.g., head of the functions)</li>
		<li>The project can run with the selection of an option to select the type of sorting algorithm, the type of array, and it's size. (it can be set directly in a program with comments to tell what parameters need to change to generate the results, or a subset of the results).</li>
		<li>The project contains a class Array that you have created.</li>
		<li>The class Array uses template.</li>
		<li>The project uses the prototype design pattern (even if you have only 1 data structure in this project, the class array is part of the multiple classes you are doing in the labs).</li>
	</ol>
<b>Functions</b>
	<ol>
		<li>The measurement functions</li>
		<li>Generate of the simulation (main function)</li>
		<li>Creation of a sorted array</li>
		<li>Creation of a completely shuffled array</li>
		<li>Creation of a shuffled array at 10%</li>
		<li>Insertion sort</li>
		<li>Selection sort</li>
		<li>Bubble sort</li>
		<li>Partition function (for Quick sort)</li>
		<li>Quick sort</li>
		<li> Merge sorted array (for Merge sort)</li>
		<li>Merge sort</li>
	</ol>

<b>Report</b>(30%) The report should not contain any snippet of code in the report.
	<ol>
		<li>Style and presentation</li>
		<li>Appropriate structure</li>
		<li>Introduction goal of the project</li>
		<li>Methods: Brief reminder about what was implemented</li>
		<li>Results: Tables and/or Figures (bar graph) with the values (mean and standard deviation) for each condition, each method with captions. Presentation of the results in the tables. Each figure/table is properly referenced and described in the main text.</li>
		<li>Discussion: Theoretical analysis vs. the time you have observed</li>
		<li>Interpretation of the results (stat analysis)</li>
		<li>Conclusion</li>
	</ol>