#include <iostream>

using namespace std;

// Command interface for commands must implement pure virtual function execute.
class Command {
public:
	virtual void execute() = 0;
};

// The TV
class Television {
public:
	// TV constructor init volume and channel to 0.
	Television() : volume(0), channel(0) {}

	void turnOn() { cout << "The television is on" << endl << flush; }

	void turnOff() { cout << "The television is off" << endl << flush; }

	void volumeUp() { cout << "Turn volume up level is " << ++volume << "\n" << flush; }

	void volumeDown() { cout << "Turn volume down level is " << --volume << "\n" << flush; }

	void channelUp() { cout << "Turn channel up level is " << ++channel << "\n" << flush; }

	void channelDown() { cout << "Turn channel down level is " << --channel << "\n" << flush; }

private:
	int volume;
	int channel;
};

// Turn tv on.
class TVOnCommand : public Command {
public:
	TVOnCommand(Television& tele) : tv(tele) {}

	virtual void execute() { tv.turnOn(); }

private:
	Television& tv;
};

// Turn tv off.
class TVOffCommand : public Command {
public:
	TVOffCommand(Television& tele) : tv(tele) {}

	virtual void execute() { tv.turnOff(); }

private:
	Television& tv;
};

// Turn tv volume up.
class VolumeUpCommand : public Command {
public:
	VolumeUpCommand(Television& tele) : tv(tele) {}

	virtual void execute() { tv.volumeUp(); }

private:
	Television& tv;
};

// Turn tv volume down
class VolumeDownCommand : public Command {
public:
	VolumeDownCommand(Television& tele) : tv(tele) {}

	virtual void execute() { tv.volumeDown(); }

private:
	Television& tv;
};

// Turn tv channel up.
class ChannelUpCommand : public Command {
public:
	ChannelUpCommand(Television& tele) : tv(tele) {}

	virtual void execute() { tv.channelUp(); }

private:
	Television& tv;
};

// Turn tv channel down.
class ChannelDownCommand : public Command {
public:
	ChannelDownCommand(Television& tele) : tv(tele) {}

	virtual void execute() { tv.channelDown(); }

private:
	Television& tv;
};

class TVRemote {
public:
	TVRemote(Command& volumeUpCmd, Command& volumeDownCmd, Command& channelUpCmd,
	  Command& channelDownCmd, Command& tvOnCmd, Command& tvOffCmd)
	  : volumeUpCommand(volumeUpCmd), volumeDownCommand(volumeDownCmd),
	    channelUpCommand(channelUpCmd), channelDownCommand(channelDownCmd), tvOnCommand(tvOnCmd),
	    tvOffCommand(tvOffCmd) {}

	void tvOn() { tvOnCommand.execute(); }

	void tvOff() { tvOffCommand.execute(); }

	void volumeUp() { volumeUpCommand.execute(); }

	void volumeDown() { volumeDownCommand.execute(); }

	void channelUp() { channelUpCommand.execute(); }

	void channelDown() { channelDownCommand.execute(); }

private:
	Command& tvOnCommand;
	Command& tvOffCommand;
	Command& channelUpCommand;
	Command& channelDownCommand;
	Command& volumeUpCommand;
	Command& volumeDownCommand;
};

int main(int argc, char* argv[]) {
	Television myTV;
	TVOnCommand tvOn(myTV);
	TVOffCommand tvOff(myTV);
	ChannelDownCommand chDwnCmd(myTV);
	ChannelUpCommand chUpCmd(myTV);
	VolumeUpCommand volUpCmd(myTV);
	VolumeDownCommand volDwnCmd(myTV);

	TVRemote remote(volUpCmd, volDwnCmd, chUpCmd, chDwnCmd, tvOn, tvOff);

	remote.tvOn();
	remote.channelUp();
	remote.channelUp();
	remote.channelUp();
	remote.volumeUp();
	remote.volumeUp();
	remote.channelDown();
	remote.volumeDown();
	remote.tvOff();

	return 0;
}