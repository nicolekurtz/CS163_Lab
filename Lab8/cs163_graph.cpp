#include "cs163_graph.h"
using namespace std;

/* Implement these three functions for this lab */
table::table(int size)
{
      //Allocate the adjacency list and set each
      //head pointer to NULL
      adjacency_list = new vertex[size];
      list_size = size;

      for(int i = 0; i < size; ++i)
      {
          adjacency_list[i].entry = NULL;
          adjacency_list[i].head = NULL;
      }
}

//Store the vertex at this location.
int table::insert_vertex(const journal_entry & to_add)
{
        int index = 0;

        while(adjacency_list[index].entry && index < list_size)
        {
            ++index;
        }
        
        if(index == list_size)
            return 0;

        adjacency_list[index].entry = new journal_entry;
        adjacency_list[index].entry->copy_entry(to_add);

        return 1;
}

//Attach an edge to a vertex
int table::insert_edge(char * current_vertex, char * to_attach)
{
       //Attach this vertices edge to the specified vertex
       int vertex_index = find_location(current_vertex);
       int edge_index = find_location(to_attach);

       if(vertex_index == list_size || edge_index == list_size)
           return 0;
        
       node * temp = new node; 
       temp->adjacent = &adjacency_list[edge_index];
       temp->next = adjacency_list[vertex_index].head;
       adjacency_list[vertex_index].head = temp;
}

//Display all vertices adjacent to the one specified
int table::display_adjacent(char * key_value)
{
    int index = find_location(key_value);
    if(index == list_size || !adjacency_list[index].head)
        return 0;

    node * hold = adjacency_list[index].head;
    while(hold)
    {
        hold->adjacent->entry->display();
        hold = hold->next;
    }
    
}

//Find a location in the graph
//Consider this a helper function foro all of the other member functions!
int table::find_location(char * key_value)
{
      //return the location of this particular key value 
        int match_index = list_size;
        for(int i = 0; i < list_size; ++i)
        {
            if(adjacency_list[i].entry)
            {
                if(adjacency_list[i].entry->compare(key_value))
                        match_index = i;
            }
        }
        
        return match_index;
}


