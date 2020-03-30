#include <string>
#include "test_runner.h"

using namespace std;

class Editor {
public:
    Editor(){
        text = "";
        it = text.begin();
    }

    void Left(){
        it--;
    }

    void Right(){
        it++;
    }

    void Insert(char token){
        text.insert(it, token);
        it += 1;
    }

    void Cut(size_t tokens = 1){
        auto idx = distance(text.begin(), it);
        clipboard = text.substr(idx, tokens);
        text.erase(it, it + tokens);
    }

    void Copy(size_t tokens = 1){
        auto idx = distance(text.begin(), it);
        clipboard = text.substr(idx, tokens);
    }

    void Paste(){
        text.insert(it, clipboard.begin(), clipboard.end());
        it += clipboard.size();
    }

    string GetText() const {
        return text;
    }

private:
    string text;
    string::iterator it;
    string clipboard;
};

void TypeText(Editor& editor, const string& text) {
    for(char c : text) {
        editor.Insert(c);
    }
}

void TestCopyPaste() {
    Editor editor;
    const size_t text_len = 12;
    TypeText(editor, "hello, world");

    for(size_t i = 0; i < text_len; ++i) {
        editor.Left();
    }

    editor.Copy(5);
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "hellohello, world");

    editor.Copy(0);
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "hellohello, world");

    editor.Copy(14);
    editor.Paste();
    ASSERT_EQUAL(editor.GetText(), "hellohello, worldhello, world");

    editor.Copy();
    editor.Paste();
    ASSERT_EQUAL(editor.GetText(), "hellohello, worldhhello, world");

    editor.Paste();
    ASSERT_EQUAL(editor.GetText(), "hellohello, worldhhhello, world");

    for (const char c : editor.GetText()) {
        editor.Right();
    }

    editor.Copy();
    editor.Paste();
    ASSERT_EQUAL(editor.GetText(), "hellohello, worldhhhello, world");

    editor.Insert('!');
    editor.Paste();
    ASSERT_EQUAL(editor.GetText(), "hellohello, worldhhhello, world!");
}

void TestEditing() {
    {
        Editor editor;

        const size_t text_len = 12;
        const size_t first_part_len = 7;
        TypeText(editor, "hello, world");
        for(size_t i = 0; i < text_len; ++i) {
            editor.Left();
        }
        editor.Cut(first_part_len);
        for(size_t i = 0; i < text_len - first_part_len; ++i) {
            editor.Right();
        }
        TypeText(editor, ", ");
        editor.Paste();
        editor.Left();
        editor.Left();
        editor.Cut(3);

        ASSERT_EQUAL(editor.GetText(), "world, hello");
    }
    {
        Editor editor;

        TypeText(editor, "misprnit");
        editor.Left();
        editor.Left();
        editor.Left();
        editor.Cut(1);
        editor.Right();
        editor.Paste();

        ASSERT_EQUAL(editor.GetText(), "misprint");
    }
}

void TestReverse() {
    Editor editor;

    const string text = "esreveR";
    for(char c : text) {
        editor.Insert(c);
        editor.Left();
    }

    ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
    Editor editor;
    ASSERT_EQUAL(editor.GetText(), "");

    editor.Left();
    editor.Left();
    editor.Right();
    editor.Right();
    editor.Copy(0);
    editor.Cut(0);
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
    Editor editor;

    editor.Paste();
    TypeText(editor, "example");
    editor.Left();
    editor.Left();
    editor.Paste();
    editor.Right();
    editor.Paste();
    editor.Copy(0);
    editor.Paste();
    editor.Left();
    editor.Cut(0);
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "example");
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestEditing);
    RUN_TEST(tr, TestReverse);
    RUN_TEST(tr, TestNoText);
    RUN_TEST(tr, TestEmptyBuffer);
    return 0;
}