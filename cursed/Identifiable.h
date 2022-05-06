#pragma once

namespace IMEX
{
	class Identifiable
	{
	protected:

		int ID = 0;

	public:

		Identifiable() {}
		Identifiable(int newID) : ID(newID) {}
		Identifiable(const Identifiable& other) : ID(other.ID) {}

		int GetID() const { return ID; }
		void SetID(int newID) { ID = newID; }
	};
}
