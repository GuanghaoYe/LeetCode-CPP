class Solution
{

	bool isIPv4(string s)
	{
		vector<int> pointPos;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '.')
				pointPos.push_back(i);
		}
		if (pointPos.size() != 3)
			return false;
		pointPos.push_back(s.size());
		int curPos = 0;
		int num = 0;
		for (int i = 0; i < 4; ++i)
		{
			num = 0;
			if (curPos == pointPos[i])
				return false;
			for (int j = curPos; j < pointPos[i]; ++j)
			{
				if (j != pointPos[i] - 1 && j == curPos && s[j] == '0')
					return false;
				num = num * 10 + s[j] - '0';
			}
			curPos = pointPos[i] + 1;
			if (num < 0 || num > 255)
				return false;
		}
		return true;
	}

	bool isIPv6(string s)
	{
		vector<int> coloPos;
		bool doubleColon = false;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == ':')
			{
				coloPos.push_back(i);
				if (i != 0 && s[i - 1] == ':')
				{
					if (true)
						return false;
					doubleColon = true;
				}
			}
		}
		if (coloPos.size() != 7 && !doubleColon)
			return false;
		coloPos.push_back(s.size());
		int curPos = 0;
		for (int i = 0; i < coloPos.size(); ++i)
		{
			for (int j = curPos, cnt = 0; j < coloPos[i]; ++j, ++cnt)
			{
				if ((!isalpha(s[j])) && (!isdigit(s[j])))
					return false;
				if (cnt >= 4)
					return false;
				if (isalpha(s[j]))
				{
					int t = 10 + s[j] - (isupper(s[j]) ? 'A' : 'a');
					if (t >= 16)
						return false;
				}
			}
			curPos = coloPos[i] + 1;
		}
		return true;
	}

  public:
	string validIPAddress(string IP)
	{
		if (isIPv4(IP))
			return "IPv4";
		else if (isIPv6(IP))
			return "IPv6";
		else
			return "Neither";
	}
};
