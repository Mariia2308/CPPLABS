#include <seat.h>

#include <istream>
#include <iomanip>
#include <limits>

std::istream &operator >> (std::istream &is, STU_Entry & entry)
{
    entry.name.clear();
    entry.row.clear();
    entry.column.clear();

    size_t const maxsize = std::numeric_limits<std::streamsize>::max();

    is >> std::quoted(entry.name);  // quoted schneidet "" weg wenn vorhanden und gibt string zur!ück
    is.ignore(maxsize, ',');

    is >> std::quoted(entry.row); 
    is.ignore(maxsize, ',');

    is >> std::quoted(entry.column);

    return is;
}

std::istream &operator >> (std::istream &is, STU_vector & entries)
{
    entries.clear();

    STU_Entry temp;

    //ignore first line
    is >> temp;

    while(is >> temp)
    {
        entries.push_back(std::move(temp));
    }
    return is;
}

std::ostream &operator << (std::ostream &os, STU_Entry &entry)
{


    size_t const maxsize = std::numeric_limits<std::streamsize>::max();

    os << std::quoted(entry.name);
    os << ", ";
    os << std::quoted(entry.row);
    os << ", ";
    os << std::quoted(entry.column);
    os << std::endl;

    return os;
}

std::ostream &operator << (std::ostream &os, STU_vector &entries)
{
    STU_Entry temp;
    temp.name = "Vorname";
    temp.row = "Nachname";
    temp.column = "Geburtstag";

    os << temp;
    for (auto & entry : entries){
        os << entry;
    }

    return os;
}