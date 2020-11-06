#include <iostream>
#include <vector>

#define USER_MAX 6

using namespace std;

struct UserInfo
{
	char acUserName[21];
	int Level;
	int Exp;
};

//게임 방의 유저를 관리하는 클래스
//방에는 최대 6명까지 들어 갈 수 있다.
//방에 들어오는 순서 중 가장 먼저 들어 온 사람이 방장이 된다

class GameRoomUser
{
public:
	GameRoomUser();
	~GameRoomUser();

//방에서 유저 삭제
//만약 방장이 나가면 acMasterUserName에 새로운 방장의 이름을 설정 해야 한다
	bool DelUser(char* pcUserName)
	{
		for (size_t i = 0; i < USER_MAX; i++)
		{
			if (memcmp(pcUserName, Users[i].acUserName, sizeof(pcUserName)) == false)
			{
				Users.erase(Users.begin() + i);
				memcpy(acMasterUserName, Users.begin()->acUserName, sizeof(pcUserName));
			}
		}
	}

	//방에 유저가 없는지 조사. 없으면 true 리턴
	bool IsEmpty()
	{
		if (Users.empty() == false)
			return false;
		else
			return true;
	}

	//방에 유저가 꽉 찼는지 조사, 꽉 찼다면 true 리턴
	bool IsFull()
	{
		if (Users.size() == 6)
			return true;
		else
			return false;
	}

	//특정 유저의 정보
	UserInfo& GetUserOfName(char* pcName)
	{
		for (size_t i = 0; i < USER_MAX; i++)
		{
			if (memcmp(pcName, Users[i].acUserName, sizeof(pcName)) == false)
			{
				cout << "Name : " << Users[i].acUserName << endl;
				cout << "Level : " << Users[i].Level << endl;
				cout << "Exp : " << Users[i].Exp << endl;
			}
		}
	}

	//방장의 유저 정보
	UserInfo& GetMasterUser()
	{
		cout << "Name : " << Users.begin()->acUserName << endl;
		cout << "Level : " << Users.begin()->Level << endl;
		cout << "Exp : " << Users.begin()->Exp << endl;
	}

	//가장 마지막으로 방에 들어온 유저의 정보
	UserInfo& GetUserOfLastOrder()
	{
		cout << "Name : " << Users.end()->acUserName << endl;
		cout << "Level : " << Users.end()->Level << endl;
		cout << "Exp : " << Users.end()->Exp << endl;
	}

	//특정 순서에 들어온 유저를 쫒아낸다.
	bool BanUser(int OrderNum)
	{
		cout << "Name : " << Users[OrderNum].acUserName << endl;
		cout << "Level : " << Users[OrderNum].Level << endl;
		cout << "Exp : " << Users[OrderNum].Exp << endl;
	}

	//모든 유저를 삭제한다.
	void Clear()
	{
		Users.clear();
	}

private:
	vector<UserInfo> Users;
	char acMasterUserName[21]; //방장의 이름
};

GameRoomUser::GameRoomUser()
{
}

GameRoomUser::~GameRoomUser()
{
}

int main()
{
	return 0;
}