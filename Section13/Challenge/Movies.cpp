/******************************************************************
 * Section 13 Challenge
 * Movies.h
 * 
 * Models a collection of Movies as a std::vector
 * 
 * ***************************************************************/
#include <iostream>
#include "Movies.h"

 /*************************************************************************
    Movies no-args constructor
**************************************************************************/
Movies::Movies() {
}

/*************************************************************************
    Movies destructor
**************************************************************************/
Movies::~Movies() {
}

  /*************************************************************************
    add_movie expects the name of the move, rating and watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    
    If it does then return false since the movie already exists
    Otherwise, create a movie object from the provided information
    and add that movie object to the movies vector and return true
    *********************************************************************/
bool Movies::add_movie(std::string name, std::string rating, int watched) {
    size_t size = movies.size();
    
    for(size_t i {0}; i < size; i ++) {  // look through movies vector if movie is already in
        if(name == movies[i].get_name()) {
            return false;  // if movie already exists, return false
        }
    }
    
    Movie new_movie(name, rating, watched);  // if movie is not in vector, add it and return true
    movies.push_back(new_movie);
    
    return true;
}

 /*************************************************************************
    increment_watched expects the name of the move to increment the
    watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    If it does then increment that objects watched by 1 and return true.

    Otherwise, return false since then no movies object with the movie name
    provided exists to increment
    *********************************************************************/
bool Movies::increment_watched(std::string name) {
   size_t size = movies.size();
    
    for(size_t i {0}; i < size; i ++) {  // look through movies vector if movie is already in
        if(name == movies[i].get_name()) {
            movies[i].increment_watched();
            return true;  // if movie already exists, increment and return true 
        }
    }
    
   return false;  // otherwise return false
}

/*************************************************************************
    display
    
    display all the movie objects in the movies vector.
    for each movie call the movie.display method so the movie
    object displays itself
    *********************************************************************/
void Movies::display() const {
   
    if(movies.empty()) {
        std::cout << "Sorry, no movies to display\n" << std::endl;
    } else {
        size_t size = movies.size();
        std::cout << "\n================================================" << std::endl;
        for(size_t i {0}; i < size; i ++) {  // look through movies vector if movie is already in
            std::cout << movies[i].get_name() << ", " << movies[i].get_rating() << ", " << movies[i].get_watched() << std::endl;
        }
        std::cout << "================================================\n" << std::endl;
    }
}