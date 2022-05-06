#pragma once

namespace IMEX
{
	template <class T>
	class Identifiable
	{
	protected:

		T ID;

	public:

		Identifiable() : ID() {}
		Identifiable(T newID) : ID(newID) {}
		Identifiable(const Identifiable<T>& other) : ID(other.ID) {}

		T GetID() const { return ID; }
		void SetID(T newID) { ID = newID; }
	};
}
