// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    // This function should display 
    // Playing: followed by the song that is playing
    std::cout << "Playing: " << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display the current playlist 
    // and then the current song playing.
    for(auto i : playlist) {
        std::cout << i << std::endl;
    }
    std::cout << "Current Song: " << std::endl;
    std::cout << current_song << std::endl;
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    
    //std::cout << "To be implemented" << std::endl;
    // Your program logic goes here
    display_playlist(playlist, *current_song);
    char selection {};
    std::string song_name {};
    std::string artist_name {};
    int rating {};
    do {
        display_menu();
        selection = getchar();
        selection = toupper(selection);
        switch(selection) {
            case 'F':
                current_song = playlist.begin();
                std::cout << "Playing First Song... " << std::endl;
                play_current_song(*current_song);
                break;
            case 'N':
                std::cout << "Playing Next Song... " << std::endl;
                current_song++;
                if (current_song == playlist.end()) {
                    std::cout << "Wrapping to start of playlist" << std::endl;
                    current_song = playlist.begin();
                }
                break;
            case 'P':
                    std::cout << "Playing previous song" << std::endl;
                if (current_song == playlist.begin()) {
                    std::cout << "Wrapping to end of playlist" << std::endl;
                    current_song = playlist.end();
                }
                current_song--;
                play_current_song(*current_song);
                break;
            case 'A':
                std::cout << "Adding and Playing New Song..." << std::endl;
                std::cout << "Enter Song Name: ";
                if (std::cin.peek() == '\n' || std::cin.peek() == '\r') {  //i need this for some reason...
                    std::cin.get();
                }
                std::getline(std::cin, song_name);
                std::cout << "Enter Artist Name: ";
                std::getline(std::cin, artist_name);
                std::cout << "Enter Rating: ";
                std::cin >> rating;
                playlist.emplace(current_song, song_name, artist_name, rating);
                current_song--;
                play_current_song(*current_song);
                break;
            case 'L':
                display_playlist(playlist, *current_song);
                break;
            case 'Q':
                break;
            default:
                std::cout << "Invalid selection, try again." << std::endl;
                break;
        }
    } while(selection != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}