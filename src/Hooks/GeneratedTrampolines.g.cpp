// NOTE: This file was generated by a tool.
#include "GeneratedTrampolines.g.h"
#include <Hooks\ITrampolineClient.g.h>
#include <easyhook.h>

namespace ReSoel {
    namespace Hooks {
        BOOL GeneratedTrampolines::AllocConsoleHook() {
            if (GetDebugMode()) m_debugOut << "[AllocConsole]::()" << std::endl;
            if (m_client) m_client->AllocConsolePre();
            auto result = ::AllocConsole();
            if (m_client) m_client->AllocConsolePost(result);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::AllocConsoleHookStatic() {
            return GetInstance().AllocConsoleHook();
        } 

        BOOL GeneratedTrampolines::AttachConsoleHook(DWORD dwProcessId) {
            if (GetDebugMode()) m_debugOut << "[AttachConsole]::()" << std::endl;
            if (m_client) m_client->AttachConsolePre(dwProcessId);
            auto result = ::AttachConsole(dwProcessId);
            if (m_client) m_client->AttachConsolePost(result, dwProcessId);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::AttachConsoleHookStatic(DWORD dwProcessId) {
            return GetInstance().AttachConsoleHook(dwProcessId);
        } 

        HANDLE GeneratedTrampolines::CreateConsoleScreenBufferHook(DWORD dwDesiredAccess, DWORD dwShareMode, const SECURITY_ATTRIBUTES* lpSecurityAttributes, DWORD dwFLags, LPVOID lpScreenBufferData) {
            if (GetDebugMode()) m_debugOut << "[CreateConsoleScreenBuffer]::()" << std::endl;
            if (m_client) m_client->CreateConsoleScreenBufferPre(dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwFLags, lpScreenBufferData);
            auto result = ::CreateConsoleScreenBuffer(dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwFLags, lpScreenBufferData);
            if (m_client) m_client->CreateConsoleScreenBufferPost(result, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwFLags, lpScreenBufferData);
            return result;
        }

        HANDLE WINAPI GeneratedTrampolines::CreateConsoleScreenBufferHookStatic(DWORD dwDesiredAccess, DWORD dwShareMode, const SECURITY_ATTRIBUTES* lpSecurityAttributes, DWORD dwFLags, LPVOID lpScreenBufferData) {
            return GetInstance().CreateConsoleScreenBufferHook(dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwFLags, lpScreenBufferData);
        } 

        BOOL GeneratedTrampolines::FillConsoleOutputAttributeHook(HANDLE hConsoleOutput, WORD wAttribute, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfAttrsWritten) {
            if (GetDebugMode()) m_debugOut << "[FillConsoleOutputAttribute]::()" << std::endl;
            if (m_client) m_client->FillConsoleOutputAttributePre(hConsoleOutput, wAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten);
            auto result = ::FillConsoleOutputAttribute(hConsoleOutput, wAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten);
            if (m_client) m_client->FillConsoleOutputAttributePost(result, hConsoleOutput, wAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::FillConsoleOutputAttributeHookStatic(HANDLE hConsoleOutput, WORD wAttribute, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfAttrsWritten) {
            return GetInstance().FillConsoleOutputAttributeHook(hConsoleOutput, wAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten);
        } 

        BOOL GeneratedTrampolines::FillConsoleOutputCharacterWHook(HANDLE hConsoleOutput, WCHAR cCharacter, DWORD nLength, COORD dwWriterCoord, LPDWORD lpNumberOfCharsWritten) {
            if (GetDebugMode()) m_debugOut << "[FillConsoleOutputCharacterW]::()" << std::endl;
            if (m_client) m_client->FillConsoleOutputCharacterWPre(hConsoleOutput, cCharacter, nLength, dwWriterCoord, lpNumberOfCharsWritten);
            auto result = ::FillConsoleOutputCharacterW(hConsoleOutput, cCharacter, nLength, dwWriterCoord, lpNumberOfCharsWritten);
            if (m_client) m_client->FillConsoleOutputCharacterWPost(result, hConsoleOutput, cCharacter, nLength, dwWriterCoord, lpNumberOfCharsWritten);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::FillConsoleOutputCharacterWHookStatic(HANDLE hConsoleOutput, WCHAR cCharacter, DWORD nLength, COORD dwWriterCoord, LPDWORD lpNumberOfCharsWritten) {
            return GetInstance().FillConsoleOutputCharacterWHook(hConsoleOutput, cCharacter, nLength, dwWriterCoord, lpNumberOfCharsWritten);
        } 

        BOOL GeneratedTrampolines::FillConsoleOutputCharacterAHook(HANDLE hConsoleOutput, CHAR cCharacter, DWORD nLength, COORD dwWriterCoord, LPDWORD lpNumberOfCharsWritten) {
            if (GetDebugMode()) m_debugOut << "[FillConsoleOutputCharacterA]::()" << std::endl;
            if (m_client) m_client->FillConsoleOutputCharacterAPre(hConsoleOutput, cCharacter, nLength, dwWriterCoord, lpNumberOfCharsWritten);
            auto result = ::FillConsoleOutputCharacterA(hConsoleOutput, cCharacter, nLength, dwWriterCoord, lpNumberOfCharsWritten);
            if (m_client) m_client->FillConsoleOutputCharacterAPost(result, hConsoleOutput, cCharacter, nLength, dwWriterCoord, lpNumberOfCharsWritten);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::FillConsoleOutputCharacterAHookStatic(HANDLE hConsoleOutput, CHAR cCharacter, DWORD nLength, COORD dwWriterCoord, LPDWORD lpNumberOfCharsWritten) {
            return GetInstance().FillConsoleOutputCharacterAHook(hConsoleOutput, cCharacter, nLength, dwWriterCoord, lpNumberOfCharsWritten);
        } 

        BOOL GeneratedTrampolines::FlushConsoleInputBufferHook(HANDLE hConsoleInput) {
            if (GetDebugMode()) m_debugOut << "[FlushConsoleInputBuffer]::()" << std::endl;
            if (m_client) m_client->FlushConsoleInputBufferPre(hConsoleInput);
            auto result = ::FlushConsoleInputBuffer(hConsoleInput);
            if (m_client) m_client->FlushConsoleInputBufferPost(result, hConsoleInput);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::FlushConsoleInputBufferHookStatic(HANDLE hConsoleInput) {
            return GetInstance().FlushConsoleInputBufferHook(hConsoleInput);
        } 

        BOOL GeneratedTrampolines::FreeConsoleHook() {
            if (GetDebugMode()) m_debugOut << "[FreeConsole]::()" << std::endl;
            if (m_client) m_client->FreeConsolePre();
            auto result = ::FreeConsole();
            if (m_client) m_client->FreeConsolePost(result);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::FreeConsoleHookStatic() {
            return GetInstance().FreeConsoleHook();
        } 

        BOOL GeneratedTrampolines::ScrollConsoleScreenBufferWHook(HANDLE hConsoleOutput, const SMALL_RECT* lpScrollRectangle, const SMALL_RECT* lpClipRectangle, COORD dwDestinationOrigin, const CHAR_INFO* lpFill) {
            if (GetDebugMode()) m_debugOut << "[ScrollConsoleScreenBufferW]::()" << std::endl;
            if (m_client) m_client->ScrollConsoleScreenBufferWPre(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill);
            auto result = ::ScrollConsoleScreenBufferW(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill);
            if (m_client) m_client->ScrollConsoleScreenBufferWPost(result, hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::ScrollConsoleScreenBufferWHookStatic(HANDLE hConsoleOutput, const SMALL_RECT* lpScrollRectangle, const SMALL_RECT* lpClipRectangle, COORD dwDestinationOrigin, const CHAR_INFO* lpFill) {
            return GetInstance().ScrollConsoleScreenBufferWHook(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill);
        } 

        BOOL GeneratedTrampolines::ScrollConsoleScreenBufferAHook(HANDLE hConsoleOutput, const SMALL_RECT* lpScrollRectangle, const SMALL_RECT* lpClipRectangle, COORD dwDestinationOrigin, const CHAR_INFO* lpFill) {
            if (GetDebugMode()) m_debugOut << "[ScrollConsoleScreenBufferA]::()" << std::endl;
            if (m_client) m_client->ScrollConsoleScreenBufferAPre(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill);
            auto result = ::ScrollConsoleScreenBufferA(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill);
            if (m_client) m_client->ScrollConsoleScreenBufferAPost(result, hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::ScrollConsoleScreenBufferAHookStatic(HANDLE hConsoleOutput, const SMALL_RECT* lpScrollRectangle, const SMALL_RECT* lpClipRectangle, COORD dwDestinationOrigin, const CHAR_INFO* lpFill) {
            return GetInstance().ScrollConsoleScreenBufferAHook(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill);
        } 

        BOOL GeneratedTrampolines::SetConsoleActiveScreenBufferHook(HANDLE hConsoleOutput) {
            if (GetDebugMode()) m_debugOut << "[SetConsoleActiveScreenBuffer]::()" << std::endl;
            if (m_client) m_client->SetConsoleActiveScreenBufferPre(hConsoleOutput);
            auto result = ::SetConsoleActiveScreenBuffer(hConsoleOutput);
            if (m_client) m_client->SetConsoleActiveScreenBufferPost(result, hConsoleOutput);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::SetConsoleActiveScreenBufferHookStatic(HANDLE hConsoleOutput) {
            return GetInstance().SetConsoleActiveScreenBufferHook(hConsoleOutput);
        } 

        BOOL GeneratedTrampolines::SetConsoleCPHook(UINT wCodePageID) {
            if (GetDebugMode()) m_debugOut << "[SetConsoleCP]::()" << std::endl;
            if (m_client) m_client->SetConsoleCPPre(wCodePageID);
            auto result = ::SetConsoleCP(wCodePageID);
            if (m_client) m_client->SetConsoleCPPost(result, wCodePageID);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::SetConsoleCPHookStatic(UINT wCodePageID) {
            return GetInstance().SetConsoleCPHook(wCodePageID);
        } 

        BOOL GeneratedTrampolines::SetConsoleCtrlHandlerHook(PHANDLER_ROUTINE HandlerRoutine, BOOL Add) {
            if (GetDebugMode()) m_debugOut << "[SetConsoleCtrlHandler]::()" << std::endl;
            if (m_client) m_client->SetConsoleCtrlHandlerPre(HandlerRoutine, Add);
            auto result = ::SetConsoleCtrlHandler(HandlerRoutine, Add);
            if (m_client) m_client->SetConsoleCtrlHandlerPost(result, HandlerRoutine, Add);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::SetConsoleCtrlHandlerHookStatic(PHANDLER_ROUTINE HandlerRoutine, BOOL Add) {
            return GetInstance().SetConsoleCtrlHandlerHook(HandlerRoutine, Add);
        } 

        BOOL GeneratedTrampolines::SetConsoleCursorInfoHook(HANDLE hConsoleOutput, const CONSOLE_CURSOR_INFO* lpConsoleCursorInfo) {
            if (GetDebugMode()) m_debugOut << "[SetConsoleCursorInfo]::()" << std::endl;
            if (m_client) m_client->SetConsoleCursorInfoPre(hConsoleOutput, lpConsoleCursorInfo);
            auto result = ::SetConsoleCursorInfo(hConsoleOutput, lpConsoleCursorInfo);
            if (m_client) m_client->SetConsoleCursorInfoPost(result, hConsoleOutput, lpConsoleCursorInfo);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::SetConsoleCursorInfoHookStatic(HANDLE hConsoleOutput, const CONSOLE_CURSOR_INFO* lpConsoleCursorInfo) {
            return GetInstance().SetConsoleCursorInfoHook(hConsoleOutput, lpConsoleCursorInfo);
        } 

        BOOL GeneratedTrampolines::SetConsoleCursorPositionHook(HANDLE hConsoleOutput, COORD dwCursorPosition) {
            if (GetDebugMode()) m_debugOut << "[SetConsoleCursorPosition]::()" << std::endl;
            if (m_client) m_client->SetConsoleCursorPositionPre(hConsoleOutput, dwCursorPosition);
            auto result = ::SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
            if (m_client) m_client->SetConsoleCursorPositionPost(result, hConsoleOutput, dwCursorPosition);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::SetConsoleCursorPositionHookStatic(HANDLE hConsoleOutput, COORD dwCursorPosition) {
            return GetInstance().SetConsoleCursorPositionHook(hConsoleOutput, dwCursorPosition);
        } 

        BOOL GeneratedTrampolines::SetConsoleDisplayModeHook(HANDLE hConsoleOutput, DWORD dwFlags, PCOORD lpNewScreenBufferDimensions) {
            if (GetDebugMode()) m_debugOut << "[SetConsoleDisplayMode]::()" << std::endl;
            if (m_client) m_client->SetConsoleDisplayModePre(hConsoleOutput, dwFlags, lpNewScreenBufferDimensions);
            auto result = ::SetConsoleDisplayMode(hConsoleOutput, dwFlags, lpNewScreenBufferDimensions);
            if (m_client) m_client->SetConsoleDisplayModePost(result, hConsoleOutput, dwFlags, lpNewScreenBufferDimensions);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::SetConsoleDisplayModeHookStatic(HANDLE hConsoleOutput, DWORD dwFlags, PCOORD lpNewScreenBufferDimensions) {
            return GetInstance().SetConsoleDisplayModeHook(hConsoleOutput, dwFlags, lpNewScreenBufferDimensions);
        } 

        BOOL GeneratedTrampolines::SetConsoleModeHook(HANDLE hConsoleHandle, DWORD dwMode) {
            if (GetDebugMode()) m_debugOut << "[SetConsoleMode]::()" << std::endl;
            if (m_client) m_client->SetConsoleModePre(hConsoleHandle, dwMode);
            auto result = ::SetConsoleMode(hConsoleHandle, dwMode);
            if (m_client) m_client->SetConsoleModePost(result, hConsoleHandle, dwMode);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::SetConsoleModeHookStatic(HANDLE hConsoleHandle, DWORD dwMode) {
            return GetInstance().SetConsoleModeHook(hConsoleHandle, dwMode);
        } 

        BOOL GeneratedTrampolines::SetConsoleOutputCPHook(UINT wCodePageId) {
            if (GetDebugMode()) m_debugOut << "[SetConsoleOutputCP]::()" << std::endl;
            if (m_client) m_client->SetConsoleOutputCPPre(wCodePageId);
            auto result = ::SetConsoleOutputCP(wCodePageId);
            if (m_client) m_client->SetConsoleOutputCPPost(result, wCodePageId);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::SetConsoleOutputCPHookStatic(UINT wCodePageId) {
            return GetInstance().SetConsoleOutputCPHook(wCodePageId);
        } 

        BOOL GeneratedTrampolines::SetConsoleScreenBufferInfoExHook(HANDLE hConsoleOutput, PCONSOLE_SCREEN_BUFFER_INFOEX lpConsoleScreenBufferInfoEx) {
            if (GetDebugMode()) m_debugOut << "[SetConsoleScreenBufferInfoEx]::()" << std::endl;
            if (m_client) m_client->SetConsoleScreenBufferInfoExPre(hConsoleOutput, lpConsoleScreenBufferInfoEx);
            auto result = ::SetConsoleScreenBufferInfoEx(hConsoleOutput, lpConsoleScreenBufferInfoEx);
            if (m_client) m_client->SetConsoleScreenBufferInfoExPost(result, hConsoleOutput, lpConsoleScreenBufferInfoEx);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::SetConsoleScreenBufferInfoExHookStatic(HANDLE hConsoleOutput, PCONSOLE_SCREEN_BUFFER_INFOEX lpConsoleScreenBufferInfoEx) {
            return GetInstance().SetConsoleScreenBufferInfoExHook(hConsoleOutput, lpConsoleScreenBufferInfoEx);
        } 

        BOOL GeneratedTrampolines::SetConsoleScreenBufferSizeHook(HANDLE hConsoleOutput, COORD dwSize) {
            if (GetDebugMode()) m_debugOut << "[SetConsoleScreenBufferSize]::()" << std::endl;
            if (m_client) m_client->SetConsoleScreenBufferSizePre(hConsoleOutput, dwSize);
            auto result = ::SetConsoleScreenBufferSize(hConsoleOutput, dwSize);
            if (m_client) m_client->SetConsoleScreenBufferSizePost(result, hConsoleOutput, dwSize);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::SetConsoleScreenBufferSizeHookStatic(HANDLE hConsoleOutput, COORD dwSize) {
            return GetInstance().SetConsoleScreenBufferSizeHook(hConsoleOutput, dwSize);
        } 

        BOOL GeneratedTrampolines::SetConsoleTextAttributeHook(HANDLE hConsoleOutput, WORD wAttributes) {
            if (GetDebugMode()) m_debugOut << "[SetConsoleTextAttribute]::()" << std::endl;
            if (m_client) m_client->SetConsoleTextAttributePre(hConsoleOutput, wAttributes);
            auto result = ::SetConsoleTextAttribute(hConsoleOutput, wAttributes);
            if (m_client) m_client->SetConsoleTextAttributePost(result, hConsoleOutput, wAttributes);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::SetConsoleTextAttributeHookStatic(HANDLE hConsoleOutput, WORD wAttributes) {
            return GetInstance().SetConsoleTextAttributeHook(hConsoleOutput, wAttributes);
        } 

        BOOL GeneratedTrampolines::SetConsoleTitleWHook(WCHAR* lpConsoleTitle) {
            if (GetDebugMode()) m_debugOut << "[SetConsoleTitleW]::()" << std::endl;
            if (m_client) m_client->SetConsoleTitleWPre(lpConsoleTitle);
            auto result = ::SetConsoleTitleW(lpConsoleTitle);
            if (m_client) m_client->SetConsoleTitleWPost(result, lpConsoleTitle);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::SetConsoleTitleWHookStatic(WCHAR* lpConsoleTitle) {
            return GetInstance().SetConsoleTitleWHook(lpConsoleTitle);
        } 

        BOOL GeneratedTrampolines::SetConsoleTitleAHook(CHAR* lpConsoleTitle) {
            if (GetDebugMode()) m_debugOut << "[SetConsoleTitleA]::()" << std::endl;
            if (m_client) m_client->SetConsoleTitleAPre(lpConsoleTitle);
            auto result = ::SetConsoleTitleA(lpConsoleTitle);
            if (m_client) m_client->SetConsoleTitleAPost(result, lpConsoleTitle);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::SetConsoleTitleAHookStatic(CHAR* lpConsoleTitle) {
            return GetInstance().SetConsoleTitleAHook(lpConsoleTitle);
        } 

        BOOL GeneratedTrampolines::SetConsoleWindowInfoHook(HANDLE hConsoleOutput, BOOL bAbsolute, const SMALL_RECT* lpConsoleWindow) {
            if (GetDebugMode()) m_debugOut << "[SetConsoleWindowInfo]::()" << std::endl;
            if (m_client) m_client->SetConsoleWindowInfoPre(hConsoleOutput, bAbsolute, lpConsoleWindow);
            auto result = ::SetConsoleWindowInfo(hConsoleOutput, bAbsolute, lpConsoleWindow);
            if (m_client) m_client->SetConsoleWindowInfoPost(result, hConsoleOutput, bAbsolute, lpConsoleWindow);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::SetConsoleWindowInfoHookStatic(HANDLE hConsoleOutput, BOOL bAbsolute, const SMALL_RECT* lpConsoleWindow) {
            return GetInstance().SetConsoleWindowInfoHook(hConsoleOutput, bAbsolute, lpConsoleWindow);
        } 

        BOOL GeneratedTrampolines::SetCurrentConsoleFontExHook(HANDLE hConsoleOutput, BOOL bMaximumWindow, PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx) {
            if (GetDebugMode()) m_debugOut << "[SetCurrentConsoleFontEx]::()" << std::endl;
            if (m_client) m_client->SetCurrentConsoleFontExPre(hConsoleOutput, bMaximumWindow, lpConsoleCurrentFontEx);
            auto result = ::SetCurrentConsoleFontEx(hConsoleOutput, bMaximumWindow, lpConsoleCurrentFontEx);
            if (m_client) m_client->SetCurrentConsoleFontExPost(result, hConsoleOutput, bMaximumWindow, lpConsoleCurrentFontEx);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::SetCurrentConsoleFontExHookStatic(HANDLE hConsoleOutput, BOOL bMaximumWindow, PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx) {
            return GetInstance().SetCurrentConsoleFontExHook(hConsoleOutput, bMaximumWindow, lpConsoleCurrentFontEx);
        } 

        BOOL GeneratedTrampolines::SetStdHandleHook(DWORD nStdHandle, HANDLE hHandle) {
            if (GetDebugMode()) m_debugOut << "[SetStdHandle]::()" << std::endl;
            if (m_client) m_client->SetStdHandlePre(nStdHandle, hHandle);
            auto result = ::SetStdHandle(nStdHandle, hHandle);
            if (m_client) m_client->SetStdHandlePost(result, nStdHandle, hHandle);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::SetStdHandleHookStatic(DWORD nStdHandle, HANDLE hHandle) {
            return GetInstance().SetStdHandleHook(nStdHandle, hHandle);
        } 

        BOOL GeneratedTrampolines::WriteConsoleWHook(HANDLE hConsoleOutput, const VOID* lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved) {
            if (GetDebugMode()) m_debugOut << "[WriteConsoleW]::()" << std::endl;
            if (m_client) m_client->WriteConsoleWPre(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved);
            auto result = ::WriteConsoleW(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved);
            if (m_client) m_client->WriteConsoleWPost(result, hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::WriteConsoleWHookStatic(HANDLE hConsoleOutput, const VOID* lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved) {
            return GetInstance().WriteConsoleWHook(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved);
        } 

        BOOL GeneratedTrampolines::WriteConsoleAHook(HANDLE hConsoleOutput, const VOID* lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved) {
            if (GetDebugMode()) m_debugOut << "[WriteConsoleA]::()" << std::endl;
            if (m_client) m_client->WriteConsoleAPre(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved);
            auto result = ::WriteConsoleA(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved);
            if (m_client) m_client->WriteConsoleAPost(result, hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::WriteConsoleAHookStatic(HANDLE hConsoleOutput, const VOID* lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved) {
            return GetInstance().WriteConsoleAHook(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved);
        } 

        BOOL GeneratedTrampolines::WriteConsoleOutputWHook(HANDLE hConsoleOutput, const CHAR_INFO* lpBuffer, COORD dwBufferSize, COORD dwBufferCoord, PSMALL_RECT lpWriteRegion) {
            if (GetDebugMode()) m_debugOut << "[WriteConsoleOutputW]::()" << std::endl;
            if (m_client) m_client->WriteConsoleOutputWPre(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion);
            auto result = ::WriteConsoleOutputW(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion);
            if (m_client) m_client->WriteConsoleOutputWPost(result, hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::WriteConsoleOutputWHookStatic(HANDLE hConsoleOutput, const CHAR_INFO* lpBuffer, COORD dwBufferSize, COORD dwBufferCoord, PSMALL_RECT lpWriteRegion) {
            return GetInstance().WriteConsoleOutputWHook(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion);
        } 

        BOOL GeneratedTrampolines::WriteConsoleOutputAHook(HANDLE hConsoleOutput, const CHAR_INFO* lpBuffer, COORD dwBufferSize, COORD dwBufferCoord, PSMALL_RECT lpWriteRegion) {
            if (GetDebugMode()) m_debugOut << "[WriteConsoleOutputA]::()" << std::endl;
            if (m_client) m_client->WriteConsoleOutputAPre(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion);
            auto result = ::WriteConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion);
            if (m_client) m_client->WriteConsoleOutputAPost(result, hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::WriteConsoleOutputAHookStatic(HANDLE hConsoleOutput, const CHAR_INFO* lpBuffer, COORD dwBufferSize, COORD dwBufferCoord, PSMALL_RECT lpWriteRegion) {
            return GetInstance().WriteConsoleOutputAHook(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion);
        } 

        BOOL GeneratedTrampolines::WriteConsoleOutputAttributeHook(HANDLE hConsoleOutput, const WORD* lpAttribute, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfAttrsWritten) {
            if (GetDebugMode()) m_debugOut << "[WriteConsoleOutputAttribute]::()" << std::endl;
            if (m_client) m_client->WriteConsoleOutputAttributePre(hConsoleOutput, lpAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten);
            auto result = ::WriteConsoleOutputAttribute(hConsoleOutput, lpAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten);
            if (m_client) m_client->WriteConsoleOutputAttributePost(result, hConsoleOutput, lpAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::WriteConsoleOutputAttributeHookStatic(HANDLE hConsoleOutput, const WORD* lpAttribute, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfAttrsWritten) {
            return GetInstance().WriteConsoleOutputAttributeHook(hConsoleOutput, lpAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten);
        } 

        BOOL GeneratedTrampolines::WriteConsoleOutputCharacterWHook(HANDLE hConsoleOutput, WCHAR* lpCharacter, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfCharsWritten) {
            if (GetDebugMode()) m_debugOut << "[WriteConsoleOutputCharacterW]::()" << std::endl;
            if (m_client) m_client->WriteConsoleOutputCharacterWPre(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten);
            auto result = ::WriteConsoleOutputCharacterW(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten);
            if (m_client) m_client->WriteConsoleOutputCharacterWPost(result, hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::WriteConsoleOutputCharacterWHookStatic(HANDLE hConsoleOutput, WCHAR* lpCharacter, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfCharsWritten) {
            return GetInstance().WriteConsoleOutputCharacterWHook(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten);
        } 

        BOOL GeneratedTrampolines::WriteConsoleOutputCharacterAHook(HANDLE hConsoleOutput, CHAR* lpCharacter, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfCharsWritten) {
            if (GetDebugMode()) m_debugOut << "[WriteConsoleOutputCharacterA]::()" << std::endl;
            if (m_client) m_client->WriteConsoleOutputCharacterAPre(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten);
            auto result = ::WriteConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten);
            if (m_client) m_client->WriteConsoleOutputCharacterAPost(result, hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::WriteConsoleOutputCharacterAHookStatic(HANDLE hConsoleOutput, CHAR* lpCharacter, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfCharsWritten) {
            return GetInstance().WriteConsoleOutputCharacterAHook(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten);
        } 

        BOOL GeneratedTrampolines::WriteFileHook(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped) {
            if (GetDebugMode()) m_debugOut << "[WriteFile]::()" << std::endl;
            if (m_client) m_client->WriteFilePre(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);
            auto result = ::WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);
            if (m_client) m_client->WriteFilePost(result, hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::WriteFileHookStatic(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped) {
            return GetInstance().WriteFileHook(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);
        } 


        GeneratedTrampolines::HookTable GeneratedTrampolines::BuildHookTable() const {
            static const char* kernel32Dll = "kernel32.dll";
            return HookTable{
                std::make_tuple(kernel32Dll, "AllocConsole", (void*)AllocConsoleHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "AttachConsole", (void*)AttachConsoleHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "CreateConsoleScreenBuffer", (void*)CreateConsoleScreenBufferHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "FillConsoleOutputAttribute", (void*)FillConsoleOutputAttributeHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "FillConsoleOutputCharacterW", (void*)FillConsoleOutputCharacterWHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "FillConsoleOutputCharacterA", (void*)FillConsoleOutputCharacterAHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "FlushConsoleInputBuffer", (void*)FlushConsoleInputBufferHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "FreeConsole", (void*)FreeConsoleHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "ScrollConsoleScreenBufferW", (void*)ScrollConsoleScreenBufferWHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "ScrollConsoleScreenBufferA", (void*)ScrollConsoleScreenBufferAHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "SetConsoleActiveScreenBuffer", (void*)SetConsoleActiveScreenBufferHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "SetConsoleCP", (void*)SetConsoleCPHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "SetConsoleCtrlHandler", (void*)SetConsoleCtrlHandlerHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "SetConsoleCursorInfo", (void*)SetConsoleCursorInfoHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "SetConsoleCursorPosition", (void*)SetConsoleCursorPositionHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "SetConsoleDisplayMode", (void*)SetConsoleDisplayModeHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "SetConsoleMode", (void*)SetConsoleModeHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "SetConsoleOutputCP", (void*)SetConsoleOutputCPHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "SetConsoleScreenBufferInfoEx", (void*)SetConsoleScreenBufferInfoExHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "SetConsoleScreenBufferSize", (void*)SetConsoleScreenBufferSizeHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "SetConsoleTextAttribute", (void*)SetConsoleTextAttributeHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "SetConsoleTitleW", (void*)SetConsoleTitleWHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "SetConsoleTitleA", (void*)SetConsoleTitleAHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "SetConsoleWindowInfo", (void*)SetConsoleWindowInfoHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "SetCurrentConsoleFontEx", (void*)SetCurrentConsoleFontExHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "SetStdHandle", (void*)SetStdHandleHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "WriteConsoleW", (void*)WriteConsoleWHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "WriteConsoleA", (void*)WriteConsoleAHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "WriteConsoleOutputW", (void*)WriteConsoleOutputWHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "WriteConsoleOutputA", (void*)WriteConsoleOutputAHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "WriteConsoleOutputAttribute", (void*)WriteConsoleOutputAttributeHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "WriteConsoleOutputCharacterW", (void*)WriteConsoleOutputCharacterWHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "WriteConsoleOutputCharacterA", (void*)WriteConsoleOutputCharacterAHookStatic, HOOK_TRACE_INFO{}),
                std::make_tuple(kernel32Dll, "WriteFile", (void*)WriteFileHookStatic, HOOK_TRACE_INFO{}),
            };
        }
    }
}