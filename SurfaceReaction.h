#ifndef SURFACE_REACTION_H
#define SURFACE_REACTION_H

#include <string>
using namespace std;

class SurfaceReaction
{
	public:
		SurfaceReaction();
		string getMessage();
		void setMessage(string);
		
	private:
		string message;
};

#endif //SURFACE_REACTION_H