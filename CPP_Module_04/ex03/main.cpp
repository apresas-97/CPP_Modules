#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define DIM "\033[2m"
#define ITALIC "\033[3m"
// #define RED "\033[31m" // Unused
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
// #define BLUE "\033[34m" // Unused
// #define MAGENTA "\033[35m" // Unused
#define CYAN "\033[36m"
#define BR_RED "\033[91m"
#define BR_GREEN "\033[92m"
#define BR_YELLOW "\033[93m"
#define BR_BLUE "\033[94m" // Unused
#define BR_MAGENTA "\033[95m"
#define BR_CYAN "\033[96m"
#define BR_WHITE "\033[97m"
// #define B_YELLOW BOLD YELLOW // Unused
#define COMMENT ITALIC GREEN
#define TITLE RESET BOLD CYAN
#define CODE RESET ITALIC BR_WHITE
#define ICE_F BOLD BR_CYAN
#define CURE_F BOLD BR_GREEN
#define AMATERIA_F BOLD BR_YELLOW
#define CHARACTER_F BOLD BR_BLUE
#define OUTPUT_F RESET DIM
#define KEYWORD_F BR_MAGENTA

int	main( void )
{
	std::cout << TITLE ">> Testing Materias Initialisation <<" << std::endl;
	std::cout << RESET COMMENT "// Construct a new MateriaSource object:" << std::endl;
	std::cout << CODE BOLD BR_RED "IMateriaSource* " CODE " materiaSource = " KEYWORD_F "new" BR_RED BOLD " MateriaSource" CODE "();" OUTPUT_F << std::endl;
	IMateriaSource*	materiaSource = new MateriaSource();
	std::cout << std::endl;

	std::cout << RESET COMMENT "// Construct a new Ice Materia" << std::endl;
	std::cout << CODE ICE_F "Ice*" CODE " iceMateria = " KEYWORD_F "new" CODE ICE_F " Ice" CODE "();" OUTPUT_F << std::endl;
	Ice* iceMateria = new Ice();
	std::cout << std::endl;

	std::cout << RESET COMMENT "// Construct a copy of an Ice Materia" << std::endl;
	std::cout << CODE ICE_F "Ice" CODE " iceMateriaCopy = iceMateria;" OUTPUT_F << std::endl;
	Ice iceMateriaCopy = *iceMateria;
	std::cout << std::endl;

	std::cout << RESET COMMENT "// Construct a new Cure Materia" << std::endl;
	std::cout << CODE CURE_F "Cure*" CODE " cureMateria = " KEYWORD_F "new" CODE CURE_F " Cure" CODE "();" OUTPUT_F << std::endl;
	Cure* cureMateria = new Cure();
	std::cout << std::endl;

	std::cout << RESET COMMENT "// Construct a new Cure Materia into an AMateria*" << std::endl;
	std::cout << CODE AMATERIA_F "AMateria* " CODE "cureMateria2 = " KEYWORD_F "new" CODE CURE_F " Cure" CODE "();" OUTPUT_F << std::endl;
	AMateria* cureMateria2 = new Cure();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << TITLE ">> Testing the MateriaSource <<" << std::endl;

	std::cout << CODE "materiaSource->learnMateria( " ICE_F "iceMateria" CODE " );" OUTPUT_F << std::endl;
	materiaSource->learnMateria(iceMateria);
	std::cout << CODE "materiaSource->learnMateria( " CURE_F "cureMateria" CODE " );" OUTPUT_F << std::endl;
	materiaSource->learnMateria(cureMateria);
	std::cout << CODE "materiaSource->learnMateria( " CURE_F "cureMateria2" CODE " );" OUTPUT_F << std::endl;
	materiaSource->learnMateria(cureMateria2);
	std::cout << CODE "materiaSource->learnMateria( &" ICE_F "iceMateriaCopy" CODE " );" OUTPUT_F << std::endl;
	materiaSource->learnMateria(&iceMateriaCopy);
	std::cout << std::endl;

	std::cout << RESET COMMENT "// Let's see what happens if we try to add a 5th materia to MateriaSource" << std::endl;
	std::cout << CODE AMATERIA_F "AMateria* " CODE "fifthMateria = " KEYWORD_F "new " ICE_F "Ice" CODE "();" OUTPUT_F << std::endl;
	AMateria*	fifthMateria = new Ice();
	std::cout << std::endl;

	std::cout << CODE "materiaSource->learnMateria( " AMATERIA_F "fifthMateria" CODE " );" OUTPUT_F << std::endl;
	materiaSource->learnMateria(fifthMateria);
	std::cout << std::endl;

	std::cout << CODE KEYWORD_F "delete " CODE "fifthMateria;" OUTPUT_F << std::endl;
	delete fifthMateria;
	std::cout << std::endl;
	std::cout << std::endl;

	/////////////////////////////////////////////////////////////////////////////
	std::cout << TITLE ">> Testing Characters <<" << std::endl;
	std::cout << RESET COMMENT "// We create a new Character called \"Cloud\"" << std::endl;
	std::cout << CODE CHARACTER_F "ICharacter" CODE "* cloud = " KEYWORD_F "new " CODE CHARACTER_F "Character" CODE "( \"Cloud\" );" OUTPUT_F << std::endl;
	ICharacter* cloud = new Character("Cloud");
	std::cout << std::endl;

	std::cout << RESET COMMENT "// Now we create a Materia of type \"ice\" with our materiaSource" << std::endl;
	std::cout << CODE AMATERIA_F "AMateria" CODE "* materia = materiaSource->createMateria( \"ice\" );" OUTPUT_F << std::endl;
	AMateria* materia = materiaSource->createMateria("ice");
	std::cout << std::endl;

	std::cout << RESET COMMENT "// Now we make Cloud equip it" << std::endl;
	std::cout << CODE "cloud->equip( materia );" OUTPUT_F << std::endl;
	cloud->equip(materia);
	std::cout << std::endl;

	std::cout << RESET COMMENT "// Now we reuse the same pointer for a new materia" << std::endl;
	std::cout << CODE "materia = materiaSource->createMateria( \"cure\" );" OUTPUT_F << std::endl;
	materia = materiaSource->createMateria("cure");
	std::cout << std::endl;

	std::cout << RESET COMMENT "// And we make Cloud equip it too" << std::endl;
	std::cout << CODE "cloud->equip( materia );" OUTPUT_F << std::endl;
	cloud->equip(materia);
	std::cout << std::endl;

	std::cout << RESET COMMENT "// Finally we try to create a materia of type \"piro\"" << std::endl;
	std::cout << CODE "materia = materiaSource->createMateria( \"piro\" );" OUTPUT_F << std::endl;
	materia = materiaSource->createMateria("piro");
	std::cout << RESET COMMENT "// This did not go so well, the MateriaSource hasn't learned that type" << std::endl;
	std::cout << std::endl;


	std::cout << TITLE ">> Using Materias <<" << std::endl;
	std::cout << RESET COMMENT "// Now, we'll create a new Character for Cloud to use his Materias on" << std::endl;
	std::cout << CODE CHARACTER_F "ICharacter" CODE "* heartless = " KEYWORD_F "new " CODE CHARACTER_F "Character" CODE "( \"Heartless\" );" OUTPUT_F << std::endl; 
	ICharacter* heartless = new Character("Heartless");
	std::cout << std::endl;

	std::cout << CODE "cloud->use( 0, *heartless );" OUTPUT_F << std::endl;
	cloud->use(0, *heartless);
	std::cout << std::endl;
	std::cout << CODE "cloud->use( 1, *heartless );" OUTPUT_F << std::endl;
	cloud->use(1, *heartless);
	std::cout << std::endl;

	std::cout << RESET COMMENT "// Now, we can make Cloud unequip his Materias" << std::endl;
	std::cout << CODE "cloud->unequip( 0 );" OUTPUT_F << std::endl;
	cloud->unequip(0);
	std::cout << std::endl;

	std::cout << CODE "cloud->unequip( 1 );" OUTPUT_F << std::endl;
	cloud->unequip(1);
	std::cout << RESET COMMENT "// We get a warning, we must pick the pointer of the previously unequipped Materia,\n// otherwise it might be lost and unable to be deleted" << std::endl;
	std::cout << CODE AMATERIA_F "AMateria* " CODE "droppedMateria = cloud->getDroppedMaterias();" << std::endl;
	AMateria* droppedMateria = cloud->getDroppedMaterias();
	std::cout << std::endl;
	std::cout << RESET COMMENT "// Now we can unequip safely" << std::endl;
	std::cout << CODE "cloud->unequip( 1 );" OUTPUT_F << std::endl;
	cloud->unequip(1);
	std::cout << std::endl;

	std::cout << RESET COMMENT "// Let's unequip from an empty slot in Cloud's inventory" << std::endl;
	std::cout << CODE "cloud->unequip( 2 );" OUTPUT_F << std::endl;
	cloud->unequip(2);
	std::cout << std::endl;

	std::cout << RESET COMMENT "// And now let's unequip with an index that is outside the range of Cloud's inventory" << std::endl;
	std::cout << CODE "cloud->unequip( 10 );" OUTPUT_F << std::endl;
	cloud->unequip(10);
	std::cout << std::endl;

	std::cout << RESET COMMENT "// What happens if Cloud tries to equip a Materia that is already owned?" << std::endl;
	std::cout << CODE "cloud->equip( iceMateria );" COMMENT " // This belongs to MateriaSource" OUTPUT_F << std::endl;
	cloud->equip(iceMateria);
	std::cout << std::endl;

	std::cout << TITLE ">> Testing for Character deep copy <<" RESET << std::endl;
	std::cout << COMMENT "// Let's create a new Character and give him some Materias" << std::endl;
	std::cout << CODE CHARACTER_F "Character " CODE "squall( \"Squall\" );" OUTPUT_F << std::endl;
	Character squall("Squall");
	std::cout << std::endl;

	std::cout << RESET COMMENT "// Let's equip it with two Materias with the MateriaSource" << std::endl;
	std::cout << CODE "squall.equip( materiaSource->createMateria( \"ice\" ) );" OUTPUT_F << std::endl;
	squall.equip(materiaSource->createMateria("ice"));
	std::cout << CODE "squall.equip( materiaSource->createMateria( \"cure\" ) );" OUTPUT_F << std::endl;
	squall.equip(materiaSource->createMateria("cure"));
	std::cout << std::endl;
	
	std::cout << RESET COMMENT "// Let's now create a copy of squall" << std::endl;
	std::cout << CODE CHARACTER_F "Character " CODE "leon = squall;" OUTPUT_F << std::endl;
	Character leon(squall);
	std::cout << std::endl;

	std::cout << RESET COMMENT "// Now, we can make leon drop a materia and we'll delete it" RESET << std::endl;
	std::cout << CODE "leon.unequip( 0 );" OUTPUT_F << std::endl;
	leon.unequip(0);
	std::cout << CODE AMATERIA_F "AMateria*" CODE " leonDroppedMateria = leon.getDroppedMaterias();" OUTPUT_F << std::endl;
	AMateria*	leonDroppedMateria = leon.getDroppedMaterias();
	std::cout << CODE KEYWORD_F "delete " CODE "leonDroppedMateria;" OUTPUT_F << std::endl; 
	delete leonDroppedMateria;
	std::cout << std::endl;
	std::cout << RESET COMMENT "// We can now still use Squall's equivalent materia" RESET << std::endl;
	std::cout << CODE "squall.use( 0, leon );" OUTPUT_F << std::endl;
	squall.use(0, leon);
	std::cout << RESET BOLD BR_GREEN "This shows that leon is a deep copy of squall" << std::endl;
	std::cout << std::endl;

	std::cout << TITLE ">> Deleting allocated objects <<" << std::endl;
	std::cout << RESET COMMENT "// Deleting MateriaSource" << std::endl;
	std::cout << CODE KEYWORD_F "delete " CODE "materiaSource;" OUTPUT_F << std::endl;
	delete materiaSource;
	std::cout << std::endl;
	std::cout << RESET COMMENT "// Deleting Materias" << std::endl;
	std::cout << CODE KEYWORD_F "delete " CODE "iceMateria;" OUTPUT_F << std::endl;
	delete iceMateria;
	std::cout << CODE KEYWORD_F "delete " CODE "cureMateria;" OUTPUT_F << std::endl;
	delete cureMateria;
	std::cout << CODE KEYWORD_F "delete " CODE "cureMateria2;" OUTPUT_F << std::endl;
	delete cureMateria2;
	std::cout << CODE KEYWORD_F "delete " CODE "droppedMateria;" OUTPUT_F << std::endl; 
	delete droppedMateria;
	std::cout << std::endl;
	std::cout << RESET COMMENT "// Deleting Characters" << std::endl;
	std::cout << CODE KEYWORD_F "delete " CODE "cloud;" OUTPUT_F << std::endl;
	delete cloud;
	std::cout << CODE KEYWORD_F "delete " CODE "heartless;" OUTPUT_F << std::endl;
	delete heartless;
	std::cout << std::endl;

	std::cout << RESET COMMENT "// Squall, Leon and iceMateriaCopy were allocated in the stack" << std::endl;
	std::cout << "// They will be destroyed now along with all Materias Squall and Leon have" RESET << std::endl;
	return 0;
}
