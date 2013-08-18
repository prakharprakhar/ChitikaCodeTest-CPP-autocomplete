ChitikaCodeTest-CPP-autocomplete
================================

C++ code to perform autosuggest, using Trie data structure, console input-output


Execute

		: ./out "user query"
		

Classes :

  DataHandler 
  
  		: Class based on Strategy pattern. Encapsulate each logic, and make them interchangeable.
                Strategy lets the algorithm vary independently from the clients that use it.
                Provided enum will decide the current strategy for loading the data and about
                using the data structure.
  
  CDbReader
  
  		: Abstract class to implement data loading interface
  
  
  CLoader 
  
  		: Abstract class to implement data loading into the suggested datastructure strategy 
  
  
  FileReader
  	
  		: Inherited from CDbReader, to provide reading stored queries from the file
  
  
  TrieDS
  
  		: Inherited from CLoader, stores the queries in Trie data structure, query hits are stored as 
                leaves
  
  
  Heap
  
  		: To fetch top n queries
  Node        
  
  		: A Trie node 


