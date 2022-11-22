#include "SocialNetwork.h"

int main()
{
	SocialNetwork SN;
	SN.AddNewMan("OLEG");
	SN.AddNewMan("NIKITA");
	SN.AddNewMan("NASTYA");
	SN.AddNewMan("VANYA");
	SN.AddNewMan("ZHENYA");
	

	SN.AddFriendship("OLEG", "NIKITA");
	SN.AddFriendship("NIKITA", "NASTYA");
	SN.AddFriendship("NASTYA", "VANYA");
	SN.AddFriendship("VANYA", "ZHENYA");
	

	SN.showThreeHandshakes();
}