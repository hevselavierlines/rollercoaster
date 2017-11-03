/**
	@file 		ParticleForceGeneratorRegistry.h
	@author		kmurphy
	@practical 	
	@brief		Specification of registry class to store current force generators between particles.
	*/


#ifndef FORCE_GENERATOR_REGISTRY_H
#define FORCE_GENERATOR_REGISTRY_H

#include "ParticleForceGenerators.h"

namespace YAMPE { namespace P {
		
class ForceGeneratorRegistry : public Printable {

protected:
		
	/** Private sturcture to keep track of one force generator and the 
	 	particle it applies to.
	  	*/
	struct Entry {
		Particle::Ref particle;
		ForceGenerator::Ref forceGenerator;
		
		Entry(Particle::Ref particle, ForceGenerator::Ref forceGenerator) :
			particle(particle), forceGenerator(forceGenerator) { }
	};
		
	/// Holds the list of registrations.
	typedef std::vector<Entry> Registry;
	Registry registry;
		
public:
	ForceGeneratorRegistry(String label="ForceGeneratorRegistry") : Printable(label), registry() { } ;

	/// Registers the given force generator and particle pair.
	void add(Particle::Ref particle, ForceGenerator::Ref forceGenerator);
		
	/**	Removes the given registered pair from the registry.
		Method has no effect if the pair is not registered.
		*/
	void remove(Particle::Ref particle, ForceGenerator::Ref forceGenerator);
    
    std::vector<ForceGenerator::Ref> getEntries(Particle::Ref particle);
		
	/**	Clears all registrations from the registry. This will
		not delete the particles or the force generators
		themselves, just the records of their connection.
		*/
	void clear();
		
	/// Calls all force generators to apply forces to associated particles 
	void applyForce(float dt);
	
	const String toString() const;
};

} }	// namespace YAMPE::P

#endif