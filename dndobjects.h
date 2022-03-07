#pragma once

#include <QString>
#include <vector>
#include <qdebug.h>

namespace dndobjs
{
    enum dice { d2, d4, d6, d8, d10, d12, d20, d100 };
    enum objType { adventutingGear, ammo, armour, weapon, potion, relic, ring, rod, scroll, shield, staff, tool, wand, wonderousItem };
    enum rarity { common, uncommon, rare, veryRare, legendary };
    enum weaponProperties { ammunition, finesse, heavy, light, loading, range, reach, special, thrown, twoHanded, versatile, improv, silvered };
    enum size { tiny, small, medium, large, huge, gargantuan };
    enum damageType { acid, bludgeoning, cold, fire, force, lightning, necrotic, piercing, poison, psychic, radiant, slashing, thunder };
    enum armourType { lightArmour, medArmour, heavyArmour };
    enum weaponType { club, dagger, greatClub, handAxe, javelin, lightHammer, mace, quaterstaff, sickle, spear, crossbowLight, dart, shortBow, sling, battleaxe, flail, glaive, greataxe,
                      greatsword, halberd, lance, longsword, maul, morningstar, pike, rapier, scimitar, scythe, shortsword, trident, warPick, warhammer, whip, blowgun, crossbowHand, crossbowHeavy,
                      longbow, net, improvised };
    enum stats { strength, dexterity, constitution, intelligence, wisdom, charisma };
    enum skills { acrobatics, animalHandling, arcana, athletics, deception, history, insight, intimidation, investigation, medicine, nature, perception, performance, persuasion, religion,
                  sleightOfHand, stealth, survival };
    enum magicSchools { abjuration, divination, necromancy, conjuration, transumation, evocation, illusion, enchantment };
    enum alignment { lg, ng, cg, ln, nn, cn, le, ne, ce };
    enum creatureType { abberation, beast, celestial, construct, dragon, elemental, fey, fiend, giant, humanoid, monstrosity, ooze, plant, undead };
    enum conditions { blinded, charmed, deafened, frightened, grappled, incapacitated, invisible, paralyzed, petrified, poisoned, prone, restrained, stunned, unconcious,
                      exh1, exh2, exh3, exh4, exh5, exh6 };
    enum language { commonSpeech, undercommonSpeech, elvishSpeech, gnomishSpeech, sylvanSpeech, dwarvishSpeech, giantSpeech, goblinSpeech, halflingSpeech, orcSpeech,
                     abyssalSpeech, celestialSpeech, deepSpeech, draconicSpeech, infernalSpeech, primordialSpeech };
    enum speedTypes { walking, climbing, swimming, flying };
    enum sightTypes { blindsight, darkvision, truesight };
    enum equipPos { crown, neck, torso, arms, gloves, handRight, handLeft, finger, back, belt, legs, feet };
    enum itemState { bag, equipped, nearby, lost };
    enum specialpropertyTypes { normalProperty, attackProperty, spellProperty, pointProperty };

    QString DiceText(dice d);
    QString ObjTypeText(objType o);
    QString RarityText(rarity r);
    QString WeaponPropertiesText(weaponProperties w);
    QString SizeText(size s);
    QString DamageTypeText(damageType d);
    QString ArmourTypeText(armourType a);
    QString WeaponTypeText(weaponType w);
    QString StatsText(stats s);
    QString StatsTextShort(stats s);
    QString StatsText(int s);
    QString StatsTextShort(int s);
    QString SkillsText(skills s);
    QString SkillsText(int s);
    QString MagicSchoolText(magicSchools m);
    QString AlignmentText(alignment a);
    QString CreatureTypeText(creatureType t);
    QString ConditionText(conditions c);
    QString LanguageText(language l);
    QString EquipPosText(equipPos e);
    QString SpeedText(speedTypes s);
    QString SightText(sightTypes s);

    class DDClass;
    class DDPlayerCharacter;

    stats SkillStat(skills s);
    QString SignedModifierText(int modifier);

    class DDDice
    {
    protected:
        dice d;
        ushort count;
        short modifier;

    private:
        DDDice* next;

    public:
        DDDice(dice newD, ushort newCount, short newModifier);
        DDDice(dice newD, ushort newCount, short newModifier, DDDice *n);
        DDDice();
        virtual QString ToString ();
        QString GetDiceText();
        dice GetDice();
        ushort GetDiceCount();
        short GetModifier();
        void SetModifier(short i);
        void SetCount(ushort i);
        void SetNext(DDDice *n);
        DDDice* Next();
        virtual bool MoreDice();
        //void SetDice(dice newD);
        //void SetDiceCount(ushort newCount);
    };

    class DDDamageDice : public DDDice
    {
    private:
        damageType dmgType;
        DDDamageDice *next;

    public:
        DDDamageDice(dice newD, ushort newCount, short newModifier, damageType dt);
        DDDamageDice(dice newD, ushort newCount, short newModifier, damageType dt, DDDamageDice *n);
        QString ToString ();
        QString GetDamageTypeText();
        damageType GetDamageType();
        void SetNext(DDDamageDice *n);
        DDDamageDice* Next();
        bool MoreDice();
    };

    class DDShape
    {
    protected:
        ushort size;
        QString shape;

    public:
        DDShape(ushort sz, QString sp);
        ushort GetSize();
        QString GetShape();
    };

    class DDSpell
    {
    protected:
        QString name, description, castTime, duration;
        magicSchools school;
        ushort level, range;
        bool spellComponents[3];
        QString itemComponents;
        std::vector<DDClass*> classes;

    public:
        DDSpell (QString n, QString d, QString cT, QString dur, magicSchools s, ushort lvl, ushort r);
        DDSpell();
        QString GetName();
        QString GetDescription();
        QString GetCastTime();
        QString GetDuration();
        QString GetSchoolText();
        magicSchools GetSchool();
        ushort GetLevel();
        ushort GetRange();
        QString GetSpellComponentsText();
        bool GetSpellComponent(int index);
        QString GetItemComponents();
        QString GetClassesText();
        DDClass* GetClass(int index);
        void AddClass(DDClass* c);
        void SetMagicComponents(bool v, bool s, bool i);
        void SetItemComponents(QString iC);
        virtual ushort GetMetaType();
    };

    class DDSpecialProperty
    {
    protected:
        QString name, description;
        void* func;
        int valChange;
        specialpropertyTypes type;

    public:
        DDSpecialProperty(QString n, QString d, void* f, int v, specialpropertyTypes t);
        DDSpecialProperty(QString n, QString d, specialpropertyTypes t);
        DDSpecialProperty();
        QString GetName();
        virtual QString GetDescription();
        virtual QString ToString();
        void CallFunction(DDPlayerCharacter p);
        specialpropertyTypes GetType();
        //void SetName(QString n);
        //void SetConditions(QString c);
        //void SetDescription(QString d);
    };

    class DDSpellProperty : public DDSpecialProperty
    {
    private:
        DDSpell* spell;
        ushort charges, maxCharges;

    public:
        DDSpellProperty(QString n, QString d, void* f, int v, specialpropertyTypes t, DDSpell* s, ushort mc);
        QString GetDescription();
        void UseCharge();
        void RefillCharges();
        void SetCharge(ushort c);
        //void SetMaxCharges(ushort mc);
    };

    class DDSpecialAttack : public DDSpecialProperty
    {
    private:
        DDDamageDice* dmgDie;

    public:
        DDSpecialAttack(QString n, QString d, void* f, int v, specialpropertyTypes t, DDDamageDice *dd);
        QString GetDescription();
    };

    class DDSpecialPoints : public DDSpecialProperty
    {
    private:
        QString pointsName;
        ushort points, maxPoints;

    public:
        DDSpecialPoints(QString n, QString d, void* f, int v, specialpropertyTypes t, QString pN, ushort p);
        QString GetDescription();
        ushort GetPoints();
        ushort GetMaxPoints();
        void UseCharge();
        void RegainCharge();
        void RefillCharges();
        void SetMaxCharges(int i);
    };

    class DDObject
    {
    protected:
        QString name, description;
        objType type;
        equipPos eqiupPosition;
        std::vector<DDSpecialProperty*> specialProperties;
        rarity objRarity;
        float price, weight;
        size objSize;

    public:
        DDObject(QString n, QString d, objType t, equipPos eq, rarity r, size s, float p);
        DDObject();
        QString GetName();
        QString GetDescription();
        virtual QString GetTypeText ();
        objType GetType();
        QString GetEquipmentPositionText();
        equipPos GetEquipmentPosition();
        QString GetRarityText();
        rarity GetRarity();
        QString GetSpecialPropertyText();
        DDSpecialProperty* GetSpecialProperty(int index);
        float GetPrice();
        QString GetPriceText();
        QString GetSizeText();
        size GetSize();
        ushort GetSpecialPropertyCount();
        void AddSpecialProperty(DDSpecialProperty* newP);
        std::vector<DDSpellProperty*> GetSpellProperties();
        std::vector<DDSpecialPoints*> GetSpecialPoints();
        std::vector<DDSpecialAttack*> GetSpecialAttacks();
        /*void SetName(QString n);
        void SetDescription(QString d);
        void AddSpecialProperty(DDSpecialProperty* newProperty);
        void RemoveSpecialProperty(int index);
        void SetType(objType t);
        void SetRarity(rarity r);
        void SetPrice(float p);
        void SetSize(size s);
        void SetMaterial(QString m);*/
    };

    class DDWeapon : public DDObject
    {
    private:
        DDDamageDice *dmgDie;
        std::vector<weaponProperties> properties;
        bool isMartial;
        ushort range, magicLevel;
        weaponType wpnType;

    public:
        DDWeapon(QString n, QString d, rarity r, size s, float p, weaponType t, DDDamageDice *dd, std::vector<weaponProperties> wp, bool mgic, bool mrtl, ushort ra = 0);
        DDWeapon(QString n, QString d, weaponType t, ushort diceCount = 1, ushort mgicLevel = 0, rarity r = common, ushort p = 0);
        QString GetDieText();
        DDDamageDice* GetDie(int index = 0);
        ushort GetDieCount();
        bool IsMagical();
        bool IsMartial();
        ushort GetRange();
        ushort GetMagicLevel();
        QString GetWeaponPropertiesText();
        weaponProperties GetWeaponProperty(int index);
        bool HasWeaponProperty(weaponProperties p);
        weaponType GetWeaponType();
        QString GetWeaponTypeText();
        /*void AddDmgDie (DDDamageDice d);
        void RemoveDmgDie (int index);
        void SetMagical (bool m);
        void SetDamageType(damageType d);
        void AddProperty(weaponProperties wp);
        void RemoveProperty(int index);
        void SetDamageBonus(short db);
        void SetReach(ushort r);
        void SetRange(ushort r);*/
    };

    class DDShield : public DDObject
    {
    private:
        ushort acBonus;

    public:
        DDShield (QString n, QString d, rarity r, size s, float p, ushort ac);
        ushort GetACBonus();
        //void SetACBonus(ushort ac);
    };

    class DDArmour : public DDObject
    {
    private:
        ushort ac;
        std::vector<skills> disadvantages, advantages;
        armourType armType;

    public:
        DDArmour (QString n, QString d, rarity r, size s, float p, ushort a, std::vector<skills> dadv, std::vector<skills> adv, armourType at);
        ushort GetAC();
        QString GetAdvantagesText();
        QString GetDisadvantagesText();
        skills GetAdvantage(int index);
        skills GetDisadvantage(int index);
        armourType GetType();
        QString GetTypeText();
    };

    class DDAttackSpell : public DDSpell
    {
    protected:
        DDDamageDice *dmgDie;
        short dmgBonus;

    public:
        DDAttackSpell (QString n, QString d, QString cT, QString dur, magicSchools s, ushort lvl, ushort r, DDDamageDice *dd);
        DDAttackSpell();
        QString GetDmgDiceText();
        DDDamageDice* GetDamageDie(int index);
        ushort GetMetaType();
    };

    class DDAOESpell : public DDSpell, public DDShape
    {
    protected:
        ushort size;
        QString shape;

    public:
        DDAOESpell (QString n, QString d, QString cT, QString dur, magicSchools s, ushort lvl, ushort r, ushort sz, QString sH);
        QString GetShape();
        ushort GetSize();
        ushort GetMetaType();
    };

    class DDAOEAttackSpell : public DDAttackSpell, public DDShape
    {
    private:

    public:
        DDAOEAttackSpell (QString n, QString d, QString cT, QString dur, magicSchools s, ushort lvl, ushort r, DDDamageDice *dd, ushort sz, QString sH);
        ushort GetMetaType();
    };

    class DDHealingSpell : public DDSpell
    {
    private:
        DDDice* healDice;

    public:
        DDHealingSpell (QString n, QString d, QString cT, QString dur, magicSchools s, ushort lvl, ushort r, DDDice *hD);
        DDDice* GetDice();
        QString GetDiceText();
        ushort GetMetaType();
    };

    class DDCreature
    {
    protected:
        QString name, description;
        size creatureSize;
        creatureType type;
        alignment align;
        ushort ac, hp, maxHp, speed[4], sight[3], stats[6], proficiencyBonus;
        short skills[18], savingThrows[6], initBonus;
        std::vector<enum skills> skillProficiencies;
        std::vector<enum stats> savingThrowProficiencies;
        DDDice* hitDie;
        std::vector<damageType> dmgImmunities, dmgResistances, dmgVulnarabilities;
        std::vector<DDSpecialProperty*> specialProperties;
        std::vector<DDSpell*> spells;
        std::vector<language> languages;

    public:
        DDCreature(QString n, QString d, size s, creatureType t, alignment a, ushort shr[2], ushort stt[6], std::vector<enum skills> skprof, std::vector<enum stats> svprof, ushort profBonus, DDDice *hd, std::vector<damageType> dI, std::vector<damageType> dR, std::vector<damageType> dV, std::vector<DDSpecialProperty*> sp, std::vector<DDSpell*> spll, std::vector<language> lng);
        DDCreature();
        void GetSkillsFromStats();
        QString GetName();
        QString GetDescription();
        QString GetSizeText();
        size GetSize();
        QString GetTypeText();
        creatureType GetType();
        QString GetAlignmentText();
        alignment GetAlignment();
        ushort GetAC();
        ushort GetHP();
        ushort GetMaxHP();
        ushort GetSpeed(speedTypes sp);
        ushort GetSight(sightTypes si);
        ushort GetStat(enum stats stat);
        ushort GetStat(int s);
        ushort GetSpecialPropertyCount();
        ushort GetSpellCount();
        short GetStatModifier(enum stats stat);
        short GetStatModifier(int stat);
        short GetSavingThrow(enum stats s);
        short GetSavingThrow(int stat);
        short GetSkill(enum skills skill);
        short GetSkill(int skill);
        short GetInitBonus();
        short GetProficiencyBonus();
        QString GetHitDiceText();
        DDDice* GetHitDie (int index);
        QString GetImmunityText();
        QString GetResistanceText();
        QString GetVulnarabilityText();
        damageType GetImmunity(int index);
        damageType GetResistance(int index);
        damageType GetVulnarability(int index);
        QString GetSpecialPropertyText();
        DDSpecialProperty* GetSpecialProperty(int index);
        DDSpell* GetSpell(int index);
        bool IsProficient(enum skills s);
        bool IsProficient(enum stats s);
        QString GetLanguagesText();
        language GetLangauge(int index);
        std::vector<DDSpellProperty*> GetSpellProperties();
        std::vector<DDSpecialPoints*> GetSpecialPoints();
        std::vector<DDSpecialAttack*> GetSpecialAttacks();
        void AddSpell (DDSpell *spell);
    };

    class DDMonster : public DDCreature
    {
    private:
        float challengeRating;
        ushort expGiven;

    public:
        DDMonster(QString n, QString d, size s, creatureType t, alignment a, ushort shr[3], ushort stt[6], ushort skll[18], DDDice *hd, std::vector<damageType> di, std::vector<damageType> dR, std::vector<damageType> dV, std::vector<DDSpecialProperty*> sp, std::vector<DDSpell*> spll, std::vector<language> lng, float c, ushort x);
        float GetChallengeRating();
        ushort GetEXP();
    };

    struct LevelFeature
    {
    public:
        ushort level;
        DDSpecialProperty* feature;
    };

    struct LevelSpell
    {
    public:
        ushort level;
        DDSpell* spell;
    };

    class DDSubClass
    {
    private:
        QString name;
        std::vector<LevelSpell*> subclassSpells;
        std::vector<LevelFeature*> subclassLevelFeatures;

    public:
        DDSubClass (QString n);
        DDSubClass (QString n, std::vector<LevelSpell*> spells, std::vector<LevelFeature*> features);
        DDSubClass (QString n, std::vector<LevelFeature*> features);
        QString GetName();
        DDSpell* GetSpellByLevel(int level);
        DDSpecialProperty* GetFeatureByLevel(int level);
    };

    class DDClass
    {
    protected:
        QString name;
        dice hitDie;
        ushort spellSlotsPerLevel[20][9];
        std::vector<armourType> armourProficiencies;
        bool martialProficent;
        stats savingThrowProficiencies[2];
        skills possibleSkillProfinciencies[6];
        std::vector<LevelFeature*> levelFeatures;
        DDSubClass* subClass;
        bool spellsUnlocked;
        stats spellStat;

    public:
        DDClass (QString n, dice hD, std::vector<armourType> aP, bool m, stats *sT, skills *prof, DDSubClass *sC);
        DDClass (QString n, dice hD, std::vector<armourType> aP, bool m, stats *sT, skills *prof, DDSubClass *sC, stats s);
        DDClass (QString n, dice hD, std::vector<armourType> aP, bool m, stats *sT, skills *prof, std::vector<LevelFeature*> lF, DDSubClass *sC, bool spells);
        QString GetName();
        dice GetHitDie();
        int SpellSlotsAtLevel (int spellLevel, int playerLevel);
        QString GetArmourProficenciesText();
        armourType GetArmourProficiency (int index);
        bool ProficientInArmour (armourType armour);
        bool ProficientInMartial ();
        stats GetSavingThrowProfiency(int index);
        skills GetSkillProficency(int index);
        LevelFeature* GetLevelFeature(int index);
        DDSpecialProperty* GetLevelFeatureByLevel (int level);
        DDSubClass* GetSubClass();
        bool CanCastSpells();
        stats GetSpellStat();
        ushort GetLevelFeatureCount();
    };

    struct AbilityScoreImprovement
    {
    public:
        stats stat;
        ushort improveAmount;
    };

    class DDSubRace
    {
    private:
        QString name;
        std::vector<AbilityScoreImprovement*> abilityScores;
        std::vector<DDSpecialProperty*> specialProperties;

    public:
        DDSubRace(QString n, std::vector<AbilityScoreImprovement*> aS, std::vector<DDSpecialProperty*> sP);
        DDSubRace(QString n);
        DDSubRace(QString n, AbilityScoreImprovement *aS);
        QString GetName();
        AbilityScoreImprovement* GetStatImprovement(int index);
        DDSpecialProperty* GetSpecialProperty(int index);
        void AddSpecialProperty(DDSpecialProperty* s);
    };

    class DDRace
    {
    private:
        QString name;
        std::vector<AbilityScoreImprovement*> abilityScores;
        std::vector<DDSpecialProperty*> specialProperties;
        DDSubRace* subRace;
        size raceSize;
        creatureType raceType;

    public:
        DDRace(QString n, std::vector<AbilityScoreImprovement*> aS, std::vector<DDSpecialProperty*> sP, DDSubRace* sR, size s, creatureType t);
        DDRace(QString n, AbilityScoreImprovement *aS, DDSubRace* sR, size s, creatureType t);
        QString GetName();
        AbilityScoreImprovement* GetStatImprovement(int index);
        DDSpecialProperty* GetSpecialProperty(int index);
        DDSubRace* GetSubRace();
        size GetSize();
        creatureType GetCreatureType();
        void AddSpecialProperty(DDSpecialProperty* addProperty);
        ushort GetSpecialPropertyCount();
    };


    class InventoryNode
    {
    private:
        InventoryNode* connections[2];
        DDObject* object;
        static ushort inventoryCount;
        itemState state;

    public:
        InventoryNode(InventoryNode *prev, DDObject *obj);
        InventoryNode(InventoryNode *prev, InventoryNode *next, DDObject *obj);
        InventoryNode();
        ~InventoryNode();
        DDObject* GetObject();
        InventoryNode* Next();
        InventoryNode* Prev();
        InventoryNode* Next(int i);
        InventoryNode* Prev(int i);
        void SetNext(InventoryNode* next);
        void SetPrev(InventoryNode* prev);
        static ushort Count();
    };

    class DDPlayerClass : public DDClass
    {
    private:
        ushort level;
        DDDice *hitDice;

    public:
        DDPlayerClass(DDClass *c, ushort l);
        DDClass* GetClass();
        ushort GetLevel();
        DDDice* GetHitDie();
        QString GetHitDieText();
        void LevelUp();
        void UpdateHitDie();
        void UpdateHitDie(short conBonus);
        int SpellSlotsAtLevel (int spellLevel);

    };

    class DDPlayerCharacter : public DDCreature
    {
    private:
        ushort age, passivePerception;
        DDRace* race;
        std::vector<DDPlayerClass*> classes;
        InventoryNode *inventory;
        DDWeapon *unarmed;
        float gold;

    public:
        DDPlayerCharacter(QString n, alignment a, ushort hp, ushort stt[6], std::vector<enum skills> skprof, std::vector<enum stats> svprof, std::vector<damageType> dI,
                std::vector<damageType> dR, std::vector<damageType> dV, std::vector<DDSpecialProperty*> sp, std::vector<DDSpell*> spll, std::vector<language> lng,
                ushort ag, DDRace* r, std::vector<DDPlayerClass*> cls, float g);
        DDPlayerCharacter(QString n, alignment a, ushort hp, ushort stt[6], std::vector<enum skills> skprof, std::vector<enum stats> svprof, std::vector<DDSpecialProperty*> sp,
                std::vector<DDSpell*> spll, std::vector<language> lng, ushort ag, DDRace* r, std::vector<DDPlayerClass*> cls, float g);
        DDPlayerCharacter(QString n, alignment a, ushort hp, ushort stt[6], std::vector<enum skills> skprof, std::vector<enum stats> svprof, std::vector<DDSpecialProperty*> sp,
                std::vector<DDSpell*> spll, std::vector<language> lng, ushort ag, DDRace* r, DDPlayerClass* cls, float g);
        QString GetCharacterName();
        ushort GetAge();
        ushort GetPassivePerception();
        DDRace* GetRace();
        DDPlayerClass* GetClass(int index);
        InventoryNode* GetHeadInventoryNode();
        float GetGold();
        DDDice* GetHitDie(int index = 0);
        std::vector<DDDice*> GetHitDice();
        ushort GetClassCount();
        std::vector<DDArmour*> GetArmours();
        std::vector<DDWeapon*> GetWeapons();
        std::vector<DDShield*> GetShields();
        void AddItem(DDObject* item);
        void RemoveItem(int index);
        DDWeapon* GetUnarmed();
        void SetUnarmed(DDWeapon* u);
    };
}
